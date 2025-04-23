/**
 * @file math_ops.h
 * @brief 数学运算函数接口
 */
#ifndef MATH_OPS_H
#define MATH_OPS_H

/**
 * @brief 计算两数之和
 * @param a 第一个数
 * @param b 第二个数
 * @return 两数之和
 */
int add(int a, int b);

/**
 * @brief 计算两数之差
 * @param a 第一个数
 * @param b 第二个数
 * @return a-b的结果
 */
int subtract(int a, int b);

/**
 * @brief 计算两数之积
 * @param a 第一个数
 * @param b 第二个数
 * @return 两数之积
 */
int multiply(int a, int b);

/**
 * @brief 计算两数之商
 * @param a 第一个数
 * @param b 第二个数
 * @return a/b的结果，如果b为0则返回0
 */
int divide(int a, int b);

/**
 * @brief 计算一个数的阶乘
 * @param n 要计算阶乘的数
 * @return n的阶乘
 */
int factorial(int n);

/**
 * @brief 计算斐波那契数列的第n项
 * @param n 要计算的项
 * @return 斐波那契数列的第n项
 */
int fibonacci(int n);

/**
 * @brief 计算最大公约数
 * @param a 第一个数
 * @param b 第二个数
 * @return a和b的最大公约数
 */
int gcd(int a, int b);

/**
 * @brief 计算数组的平均值
 * @param arr 整数数组
 * @param size 数组大小
 * @return 数组元素的平均值
 */
double average(int arr[], int size);

/**
 * @brief 计算指定范围内的所有素数
 * @param start 起始值
 * @param end 结束值
 * @param count 输出参数，返回找到的素数个数
 * @return 素数数组，调用者负责释放内存
 */
int* find_primes(int start, int end, int* count);

/**
 * @brief 初始化数学运算库
 * @return 成功返回1，失败返回0
 */
int initialize_math_ops();

#endif /* MATH_OPS_H */ 