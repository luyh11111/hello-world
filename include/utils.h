/**
 * @file utils.h
 * @brief 实用工具函数接口
 */
#ifndef UTILS_H
#define UTILS_H

/**
 * @brief 打印调试信息
 * @param message 调试消息
 */
void debug_print(const char* message);

/**
 * @brief 打印错误信息
 * @param error_code 错误代码
 * @param message 错误消息
 */
void error_log(int error_code, const char* message);

/**
 * @brief 获取当前时间戳
 * @return 返回当前时间戳字符串
 */
char* get_timestamp();

/**
 * @brief 清理资源
 * @param resource 需要清理的资源指针
 */
void cleanup_resources(void* resource);

/**
 * @brief 初始化工具库
 * @return 成功返回1，失败返回0
 */
int initialize_utils();

#endif /* UTILS_H */ 