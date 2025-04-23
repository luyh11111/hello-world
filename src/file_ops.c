/**
 * @file file_ops.c
 * @brief 文件操作函数实现
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../include/file_ops.h"
#include "../include/utils.h"
#include "../include/string_ops.h"

static int is_initialized = 0;

char* read_file(const char* filename) {
    debug_print("读取文件内容");
    if (filename == NULL) {
        error_log(3001, "文件名为NULL");
        return NULL;
    }
    
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        char error_msg[100];
        snprintf(error_msg, sizeof(error_msg), "无法打开文件: %s", filename);
        error_log(3002, error_msg);
        return NULL;
    }
    
    // 获取文件大小
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // 分配内存
    char* buffer = (char*)malloc(file_size + 1);
    if (buffer == NULL) {
        error_log(3003, "内存分配失败");
        fclose(file);
        return NULL;
    }
    
    // 读取文件内容
    size_t bytes_read = fread(buffer, 1, file_size, file);
    buffer[bytes_read] = '\0';
    
    fclose(file);
    return buffer;
}

int write_file(const char* filename, const char* content) {
    debug_print("写入文件内容");
    if (filename == NULL || content == NULL) {
        error_log(3004, "文件名或内容为NULL");
        return 0;
    }
    
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        char error_msg[100];
        snprintf(error_msg, sizeof(error_msg), "无法打开文件: %s", filename);
        error_log(3005, error_msg);
        return 0;
    }
    
    size_t content_len = strlen(content);
    size_t bytes_written = fwrite(content, 1, content_len, file);
    
    fclose(file);
    
    if (bytes_written != content_len) {
        error_log(3006, "写入文件失败");
        return 0;
    }
    
    return 1;
}

int append_file(const char* filename, const char* content) {
    debug_print("追加文件内容");
    if (filename == NULL || content == NULL) {
        error_log(3007, "文件名或内容为NULL");
        return 0;
    }
    
    FILE* file = fopen(filename, "ab");
    if (file == NULL) {
        char error_msg[100];
        snprintf(error_msg, sizeof(error_msg), "无法打开文件: %s", filename);
        error_log(3008, error_msg);
        return 0;
    }
    
    size_t content_len = strlen(content);
    size_t bytes_written = fwrite(content, 1, content_len, file);
    
    fclose(file);
    
    if (bytes_written != content_len) {
        error_log(3009, "追加文件失败");
        return 0;
    }
    
    return 1;
}

int file_exists(const char* filename) {
    debug_print("检查文件是否存在");
    if (filename == NULL) {
        error_log(3010, "文件名为NULL");
        return 0;
    }
    
    return access(filename, F_OK) == 0;
}

long get_file_size(const char* filename) {
    debug_print("获取文件大小");
    if (filename == NULL) {
        error_log(3011, "文件名为NULL");
        return -1;
    }
    
    struct stat st;
    if (stat(filename, &st) != 0) {
        char error_msg[100];
        snprintf(error_msg, sizeof(error_msg), "无法获取文件信息: %s", filename);
        error_log(3012, error_msg);
        return -1;
    }
    
    return st.st_size;
}

int copy_file(const char* source, const char* destination) {
    debug_print("复制文件");
    if (source == NULL || destination == NULL) {
        error_log(3013, "源文件或目标文件为NULL");
        return 0;
    }
    
    // 读取源文件内容
    char* content = read_file(source);
    if (content == NULL) {
        return 0;
    }
    
    // 写入目标文件
    int result = write_file(destination, content);
    free(content);
    
    return result;
}

int move_file(const char* source, const char* destination) {
    debug_print("移动文件");
    if (source == NULL || destination == NULL) {
        error_log(3014, "源文件或目标文件为NULL");
        return 0;
    }
    
    // 首先尝试直接重命名
    if (rename(source, destination) == 0) {
        return 1;
    }
    
    // 如果重命名失败（例如跨文件系统），则复制后删除
    if (copy_file(source, destination)) {
        return delete_file(source);
    }
    
    return 0;
}

int delete_file(const char* filename) {
    debug_print("删除文件");
    if (filename == NULL) {
        error_log(3015, "文件名为NULL");
        return 0;
    }
    
    if (remove(filename) != 0) {
        char error_msg[100];
        snprintf(error_msg, sizeof(error_msg), "无法删除文件: %s", filename);
        error_log(3016, error_msg);
        return 0;
    }
    
    return 1;
}

int initialize_file_ops() {
    if (is_initialized) {
        debug_print("文件操作库已经初始化");
        return 1;
    }
    
    if (!initialize_utils()) {
        error_log(3017, "初始化工具库失败");
        return 0;
    }
    
    if (!initialize_string_ops()) {
        error_log(3018, "初始化字符串操作库失败");
        return 0;
    }
    
    debug_print("文件操作库初始化成功");
    is_initialized = 1;
    return 1;
} 