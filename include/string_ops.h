/**
 * @file string_ops.h
 * @brief 字符串处理函数接口
 */
#ifndef STRING_OPS_H
#define STRING_OPS_H

/**
 * @brief 复制字符串
 * @param source 源字符串
 * @return 新分配的字符串副本，调用者负责释放内存
 */
char* string_duplicate(const char* source);

/**
 * @brief 连接两个字符串
 * @param str1 第一个字符串
 * @param str2 第二个字符串
 * @return 连接后的新字符串，调用者负责释放内存
 */
char* string_concatenate(const char* str1, const char* str2);

/**
 * @brief 将字符串转换为大写
 * @param str 源字符串
 * @return 转换后的新字符串，调用者负责释放内存
 */
char* string_to_upper(const char* str);

/**
 * @brief 将字符串转换为小写
 * @param str 源字符串
 * @return 转换后的新字符串，调用者负责释放内存
 */
char* string_to_lower(const char* str);

/**
 * @brief 翻转字符串
 * @param str 源字符串
 * @return 翻转后的新字符串，调用者负责释放内存
 */
char* string_reverse(const char* str);

/**
 * @brief 查找子字符串
 * @param str 源字符串
 * @param substr 要查找的子字符串
 * @return 子字符串在源字符串中的位置，如果未找到则返回-1
 */
int string_find(const char* str, const char* substr);

/**
 * @brief 替换字符串中的子字符串
 * @param str 源字符串
 * @param old_substr 要替换的子字符串
 * @param new_substr 替换的新子字符串
 * @return 替换后的新字符串，调用者负责释放内存
 */
char* string_replace(const char* str, const char* old_substr, const char* new_substr);

/**
 * @brief 分割字符串
 * @param str 源字符串
 * @param delimiter 分隔符
 * @param count 输出参数，返回分割后的部分数量
 * @return 分割后的字符串数组，调用者负责释放内存
 */
char** string_split(const char* str, const char* delimiter, int* count);

/**
 * @brief 初始化字符串操作库
 * @return 成功返回1，失败返回0
 */
int initialize_string_ops();

#endif /* STRING_OPS_H */ 