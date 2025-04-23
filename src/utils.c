/**
 * @file utils.c
 * @brief 实用工具函数实现
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/utils.h"
#include "../include/string_ops.h"

static int is_initialized = 0;

void debug_print(const char* message) {
    char* timestamp = get_timestamp();
    printf("[DEBUG] %s: %s\n", timestamp, message);
    free(timestamp);
}

void error_log(int error_code, const char* message) {
    char* timestamp = get_timestamp();
    fprintf(stderr, "[ERROR] %s: [%d] %s\n", timestamp, error_code, message);
    free(timestamp);
}

char* get_timestamp() {
    time_t now = time(NULL);
    char* timestamp = (char*)malloc(26);
    if (timestamp == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return NULL;
    }
    
    strftime(timestamp, 26, "%Y-%m-%d %H:%M:%S", localtime(&now));
    return timestamp;
}

void cleanup_resources(void* resource) {
    if (resource != NULL) {
        free(resource);
        debug_print("资源已释放");
    }
}

int initialize_utils() {
    if (is_initialized) {
        debug_print("工具库已经初始化");
        return 1;
    }
    
    srand((unsigned int)time(NULL));
    debug_print("工具库初始化成功");
    is_initialized = 1;
    return 1;
} 
