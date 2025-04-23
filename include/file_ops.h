/**
 * @file file_ops.h
 * @brief 文件操作函数接口
 */
#ifndef FILE_OPS_H
#define FILE_OPS_H

/**
 * @brief 读取文件内容
 * @param filename 文件名
 * @return 文件内容字符串，调用者负责释放内存
 */
char* read_file(const char* filename);

/**
 * @brief 写入文件内容
 * @param filename 文件名
 * @param content 要写入的内容
 * @return 成功返回1，失败返回0
 */
int write_file(const char* filename, const char* content);

/**
 * @brief 追加文件内容
 * @param filename 文件名
 * @param content 要追加的内容
 * @return 成功返回1，失败返回0
 */
int append_file(const char* filename, const char* content);

/**
 * @brief 检查文件是否存在
 * @param filename 文件名
 * @return 存在返回1，不存在返回0
 */
int file_exists(const char* filename);

/**
 * @brief 获取文件大小
 * @param filename 文件名
 * @return 文件大小（字节）
 */
long get_file_size(const char* filename);

/**
 * @brief 复制文件
 * @param source 源文件
 * @param destination 目标文件
 * @return 成功返回1，失败返回0
 */
int copy_file(const char* source, const char* destination);

/**
 * @brief 移动文件
 * @param source 源文件
 * @param destination 目标文件
 * @return 成功返回1，失败返回0
 */
int move_file(const char* source, const char* destination);

/**
 * @brief 删除文件
 * @param filename 文件名
 * @return 成功返回1，失败返回0
 */
int delete_file(const char* filename);

/**
 * @brief 初始化文件操作库
 * @return 成功返回1，失败返回0
 */
int initialize_file_ops();

#endif /* FILE_OPS_H */ 