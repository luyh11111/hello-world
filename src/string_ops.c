/**
 * @file string_ops.c
 * @brief 字符串处理函数实现
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/string_ops.h"
#include "../include/utils.h"

static int is_initialized = 0;

char* string_duplicate(const char* source) {
    debug_print("复制字符串");
    if (source == NULL) {
        error_log(2001, "源字符串为NULL");
        return NULL;
    }
    
    size_t len = strlen(source) + 1;
    char* result = (char*)malloc(len);
    if (result == NULL) {
        error_log(2002, "内存分配失败");
        return NULL;
    }
    
    strcpy(result, source);
    return result;
}

char* string_concatenate(const char* str1, const char* str2) {
    debug_print("连接字符串");
    if (str1 == NULL || str2 == NULL) {
        error_log(2003, "源字符串为NULL");
        return NULL;
    }
    
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = (char*)malloc(len1 + len2 + 1);
    if (result == NULL) {
        error_log(2004, "内存分配失败");
        return NULL;
    }
    
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

char* string_to_upper(const char* str) {
    debug_print("转换为大写");
    if (str == NULL) {
        error_log(2005, "源字符串为NULL");
        return NULL;
    }
    
    char* result = string_duplicate(str);
    if (result == NULL) {
        return NULL;
    }
    
    for (size_t i = 0; result[i]; i++) {
        result[i] = (char)toupper(result[i]);
    }
    
    return result;
}

char* string_to_lower(const char* str) {
    debug_print("转换为小写");
    if (str == NULL) {
        error_log(2006, "源字符串为NULL");
        return NULL;
    }
    
    char* result = string_duplicate(str);
    if (result == NULL) {
        return NULL;
    }
    
    for (size_t i = 0; result[i]; i++) {
        result[i] = (char)tolower(result[i]);
    }
    
    return result;
}

char* string_reverse(const char* str) {
    debug_print("翻转字符串");
    if (str == NULL) {
        error_log(2007, "源字符串为NULL");
        return NULL;
    }
    
    size_t len = strlen(str);
    char* result = (char*)malloc(len + 1);
    if (result == NULL) {
        error_log(2008, "内存分配失败");
        return NULL;
    }
    
    for (size_t i = 0; i < len; i++) {
        result[i] = str[len - 1 - i];
    }
    result[len] = '\0';
    
    return result;
}

int string_find(const char* str, const char* substr) {
    debug_print("查找子字符串");
    if (str == NULL || substr == NULL) {
        error_log(2009, "源字符串或子字符串为NULL");
        return -1;
    }
    
    char* ptr = strstr(str, substr);
    if (ptr == NULL) {
        return -1;
    }
    
    return (int)(ptr - str);
}

char* string_replace(const char* str, const char* old_substr, const char* new_substr) {
    debug_print("替换子字符串");
    if (str == NULL || old_substr == NULL || new_substr == NULL) {
        error_log(2010, "源字符串、旧子字符串或新子字符串为NULL");
        return NULL;
    }
    
    size_t str_len = strlen(str);
    size_t old_len = strlen(old_substr);
    size_t new_len = strlen(new_substr);
    
    // 计算替换后的字符串长度
    size_t count = 0;
    const char* tmp = str;
    while ((tmp = strstr(tmp, old_substr)) != NULL) {
        count++;
        tmp += old_len;
    }
    
    if (count == 0) {
        return string_duplicate(str);
    }
    
    size_t result_len = str_len + count * (new_len - old_len) + 1;
    char* result = (char*)malloc(result_len);
    if (result == NULL) {
        error_log(2011, "内存分配失败");
        return NULL;
    }
    
    char* dest = result;
    const char* src = str;
    const char* match;
    
    while ((match = strstr(src, old_substr)) != NULL) {
        size_t prefix_len = match - src;
        memcpy(dest, src, prefix_len);
        dest += prefix_len;
        
        memcpy(dest, new_substr, new_len);
        dest += new_len;
        
        src = match + old_len;
    }
    
    strcpy(dest, src);
    
    return result;
}

char** string_split(const char* str, const char* delimiter, int* count) {
    debug_print("分割字符串");
    if (str == NULL || delimiter == NULL || count == NULL) {
        error_log(2012, "源字符串、分隔符或计数为NULL");
        return NULL;
    }
    
    // 计算分割后的部分数量
    *count = 0;
    const char* tmp = str;
    size_t delimiter_len = strlen(delimiter);
    
    if (delimiter_len == 0) {
        error_log(2013, "分隔符长度为零");
        return NULL;
    }
    
    while ((tmp = strstr(tmp, delimiter)) != NULL) {
        (*count)++;
        tmp += delimiter_len;
    }
    (*count)++; // 最后一部分
    
    // 分配数组内存
    char** result = (char**)malloc(*count * sizeof(char*));
    if (result == NULL) {
        error_log(2014, "内存分配失败");
        *count = 0;
        return NULL;
    }
    
    // 填充数组
    char* copy = string_duplicate(str);
    if (copy == NULL) {
        free(result);
        *count = 0;
        return NULL;
    }
    
    char* token = strtok(copy, delimiter);
    int i = 0;
    
    while (token != NULL) {
        result[i] = string_duplicate(token);
        if (result[i] == NULL) {
            // 释放已分配的内存
            for (int j = 0; j < i; j++) {
                free(result[j]);
            }
            free(result);
            free(copy);
            *count = 0;
            return NULL;
        }
        i++;
        token = strtok(NULL, delimiter);
    }
    
    free(copy);
    return result;
}

int initialize_string_ops() {
    if (is_initialized) {
        debug_print("字符串操作库已经初始化");
        return 1;
    }
    
    if (!initialize_utils()) {
        error_log(2015, "初始化工具库失败");
        return 0;
    }
    
    debug_print("字符串操作库初始化成功");
    is_initialized = 1;
    return 1;
} 