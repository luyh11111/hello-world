/**
 * @file main.c
 * @brief 主程序入口
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/utils.h"
#include "include/math_ops.h"
#include "include/string_ops.h"
#include "include/file_ops.h"

// 测试函数前向声明
void test_math_functions();
void test_string_functions();
void test_file_functions();
void generate_report(const char* filename);
void cleanup_memory(void** resources, int count);
int process_command_line(int argc, char** argv);
void show_help();
void print_calculation_result(const char* operation, int result);

/**
 * @brief 主函数
 * @param argc 命令行参数数量
 * @param argv 命令行参数数组
 * @return 程序退出状态码
 */
int main(int argc, char** argv) {
    printf("C语言函数调用关系演示\n");
    printf("wwwwww\n\n");
    
    // 初始化各模块
    if (!initialize_utils()) {
        fprintf(stderr, "初始化工具库失败\n");
        return 1;
    }
    
    if (!initialize_math_ops()) {
        fprintf(stderr, "初始化数学运算库失败\n");
        return 1;
    }
    
    if (!initialize_string_ops()) {
        fprintf(stderr, "初始化字符串操作库失败\n");
        return 1;
    }
    
    if (!initialize_file_ops()) {
        fprintf(stderr, "初始化文件操作库失败\n");
        return 1;
    }
    
    // 处理命令行参数
    if (argc > 1) {
        return process_command_line(argc, argv);
    }
    
    // 执行默认测试
    printf("执行数学函数测试...\n");
    test_math_functions();
    
    printf("\n执行字符串函数测试...\n");
    test_string_functions();
    
    printf("\n执行文件函数测试...\n");
    test_file_functions();
    
    // 生成报告
    printf("\n生成测试报告...\n");
    generate_report("test_report.txt");
    
    printf("\n程序执行完毕\n");
    return 0;
}

/**
 * @brief 测试数学函数
 */
void test_math_functions() {
    // 测试基本运算
    int a = 10, b = 5;
    
    printf("基本运算测试:\n");
    print_calculation_result("加法", add(a, b));
    print_calculation_result("减法", subtract(a, b));
    print_calculation_result("乘法", multiply(a, b));
    print_calculation_result("除法", divide(a, b));
    
    // 测试阶乘
    int n = 5;
    printf("\n阶乘测试:\n");
    print_calculation_result("5的阶乘", factorial(n));
    
    // 测试斐波那契数列
    printf("\n斐波那契数列测试:\n");
    for (int i = 0; i < 10; i++) {
        printf("fibonacci(%d) = %d\n", i, fibonacci(i));
    }
    
    // 测试最大公约数
    printf("\n最大公约数测试:\n");
    printf("gcd(%d, %d) = %d\n", 48, 18, gcd(48, 18));
    
    // 测试平均值
    printf("\n平均值测试:\n");
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("数组平均值: %.2f\n", average(arr, size));
    
    // 测试素数查找
    printf("\n素数查找测试:\n");
    int count;
    int* primes = find_primes(1, 50, &count);
    if (primes != NULL) {
        printf("1到50之间的素数: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", primes[i]);
        }
        printf("\n");
        free(primes);
    }
}

/**
 * @brief 测试字符串函数
 */
void test_string_functions() {
    const char* test_string = "Hello, World!";
    
    printf("原始字符串: %s\n", test_string);
    
    // 测试字符串复制
    char* str_copy = string_duplicate(test_string);
    if (str_copy != NULL) {
        printf("字符串复制: %s\n", str_copy);
    }
    
    // 测试字符串连接
    char* str_concat = string_concatenate(test_string, " Welcome!");
    if (str_concat != NULL) {
        printf("字符串连接: %s\n", str_concat);
    }
    
    // 测试字符串转换
    char* str_upper = string_to_upper(test_string);
    if (str_upper != NULL) {
        printf("转换为大写: %s\n", str_upper);
    }
    
    char* str_lower = string_to_lower(test_string);
    if (str_lower != NULL) {
        printf("转换为小写: %s\n", str_lower);
    }
    
    // 测试字符串翻转
    char* str_reverse = string_reverse(test_string);
    if (str_reverse != NULL) {
        printf("字符串翻转: %s\n", str_reverse);
    }
    
    // 测试字符串查找
    const char* substr = "World";
    int pos = string_find(test_string, substr);
    printf("子字符串 '%s' 的位置: %d\n", substr, pos);
    
    // 测试字符串替换
    char* str_replace = string_replace(test_string, "World", "C语言");
    if (str_replace != NULL) {
        printf("字符串替换: %s\n", str_replace);
    }
    
    // 测试字符串分割
    const char* split_str = "one,two,three,four";
    int parts_count;
    char** parts = string_split(split_str, ",", &parts_count);
    if (parts != NULL) {
        printf("字符串分割 '%s':\n", split_str);
        for (int i = 0; i < parts_count; i++) {
            printf("  部分 %d: %s\n", i + 1, parts[i]);
            free(parts[i]);
        }
        free(parts);
    }
    
    // 清理内存
    void* resources[] = {str_copy, str_concat, str_upper, str_lower, str_reverse, str_replace};
    cleanup_memory(resources, sizeof(resources) / sizeof(resources[0]));
}

/**
 * @brief 测试文件函数
 */
void test_file_functions() {
    const char* test_filename = "test_file.txt";
    const char* test_content = "这是一个测试文件。\n用于测试文件操作函数。";
    
    // 测试写入文件
    printf("写入文件: %s\n", test_filename);
    if (write_file(test_filename, test_content)) {
        printf("文件写入成功\n");
    } else {
        printf("文件写入失败\n");
        return;
    }
    
    // 测试文件存在检查
    if (file_exists(test_filename)) {
        printf("文件存在: %s\n", test_filename);
    }
    
    // 测试获取文件大小
    long size = get_file_size(test_filename);
    printf("文件大小: %ld 字节\n", size);
    
    // 测试读取文件
    char* content = read_file(test_filename);
    if (content != NULL) {
        printf("文件内容:\n%s\n", content);
        free(content);
    }
    
    // 测试追加文件
    const char* append_content = "\n这是追加的内容。";
    printf("追加内容到文件\n");
    if (append_file(test_filename, append_content)) {
        printf("文件追加成功\n");
    }
    
    // 测试复制文件
    const char* copy_filename = "test_file_copy.txt";
    printf("复制文件: %s -> %s\n", test_filename, copy_filename);
    if (copy_file(test_filename, copy_filename)) {
        printf("文件复制成功\n");
    }
    
    // 测试读取复制的文件
    content = read_file(copy_filename);
    if (content != NULL) {
        printf("复制文件内容:\n%s\n", content);
        free(content);
    }
    
    // 测试删除文件
    printf("删除文件: %s\n", copy_filename);
    if (delete_file(copy_filename)) {
        printf("文件删除成功\n");
    }
    
    // 保留原始文件供查看
}

/**
 * @brief 生成测试报告
 * @param filename 报告文件名
 */
void generate_report(const char* filename) {
    char* timestamp = get_timestamp();
    
    // 生成报告内容
    char report[1024];
    snprintf(report, sizeof(report),
             "测试报告\n"
             "========\n"
             "生成时间: %s\n\n"
             "1. 数学函数测试完成\n"
             "2. 字符串函数测试完成\n"
             "3. 文件函数测试完成\n\n"
             "所有测试均已成功执行。\n",
             timestamp);
    
    // 写入报告文件
    if (write_file(filename, report)) {
        printf("测试报告已保存到: %s\n", filename);
    } else {
        printf("无法保存测试报告\n");
    }
    
    free(timestamp);
}

/**
 * @brief 清理分配的内存资源
 * @param resources 资源指针数组
 * @param count 资源数量
 */
void cleanup_memory(void** resources, int count) {
    for (int i = 0; i < count; i++) {
        if (resources[i] != NULL) {
            free(resources[i]);
            resources[i] = NULL;
        }
    }
}

/**
 * @brief 处理命令行参数
 * @param argc 参数数量
 * @param argv 参数数组
 * @return 程序退出状态码
 */
int process_command_line(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            show_help();
            return 0;
        } else if (strcmp(argv[i], "--math") == 0) {
            test_math_functions();
            return 0;
        } else if (strcmp(argv[i], "--string") == 0) {
            test_string_functions();
            return 0;
        } else if (strcmp(argv[i], "--file") == 0) {
            test_file_functions();
            return 0;
        } else if (strcmp(argv[i], "--add") == 0 && i + 2 < argc) {
            int a = atoi(argv[i + 1]);
            int b = atoi(argv[i + 2]);
            printf("%d + %d = %d\n", a, b, add(a, b));
            return 0;
        } else if (strcmp(argv[i], "--factorial") == 0 && i + 1 < argc) {
            int n = atoi(argv[i + 1]);
            printf("%d! = %d\n", n, factorial(n));
            return 0;
        }
    }
    
    printf("未知的命令行参数。使用 --help 查看帮助。\n");
    return 1;
}

/**
 * @brief 显示帮助信息
 */
void show_help() {
    printf("用法: program [选项]\n\n");
    printf("选项:\n");
    printf("  --help, -h      显示帮助信息\n");
    printf("  --math          运行数学函数测试\n");
    printf("  --string        运行字符串函数测试\n");
    printf("  --file          运行文件函数测试\n");
    printf("  --add X Y       计算X+Y的结果\n");
    printf("  --factorial N   计算N的阶乘\n");
}

/**
 * @brief 打印计算结果
 * @param operation 操作名称
 * @param result 计算结果
 */
void print_calculation_result(const char* operation, int result) {
    printf("%s结果: %d\n", operation, result);
}