/**
 * @file math_ops.c
 * @brief 数学运算函数实现
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/math_ops.h"
#include "../include/utils.h"

static int is_initialized = 0;

int add(int a, int b) {
    debug_print("执行加法运算");
    return a + b;
}

int subtract(int a, int b) {
    debug_print("执行减法运算");
    return a - b;
}

int multiply(int a, int b) {
    debug_print("执行乘法运算");
    return a * b;
}

int divide(int a, int b) {
    debug_print("执行除法运算");
    if (b == 0) {
        error_log(1001, "除数不能为零");
        return 0;
    }
    return a / b;
}

int factorial(int n) {
    debug_print("计算阶乘");
    if (n < 0) {
        error_log(1002, "阶乘不能用于负数");
        return -1;
    }
    
    if (n == 0 || n == 1) {
        return 1;
    }
    
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    debug_print("计算斐波那契数");
    if (n < 0) {
        error_log(1003, "斐波那契数列索引不能为负数");
        return -1;
    }
    
    if (n == 0) {
        return 0;
    }
    
    if (n == 1 || n == 2) {
        return 1;
    }
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int gcd(int a, int b) {
    debug_print("计算最大公约数");
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

double average(int arr[], int size) {
    debug_print("计算平均值");
    if (size <= 0) {
        error_log(1004, "数组大小必须大于零");
        return 0.0;
    }
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = add(sum, arr[i]);
    }
    
    return (double)sum / size;
}

static int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    
    if (num <= 3) {
        return 1;
    }
    
    if (num % 2 == 0 || num % 3 == 0) {
        return 0;
    }
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0;
        }
    }
    
    return 1;
}

int* find_primes(int start, int end, int* count) {
    debug_print("查找素数");
    if (start > end) {
        error_log(1005, "起始值不能大于结束值");
        *count = 0;
        return NULL;
    }
    
    // 计算素数的数量
    int prime_count = 0;
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            prime_count++;
        }
    }
    
    // 分配内存
    int* primes = (int*)malloc(prime_count * sizeof(int));
    if (primes == NULL) {
        error_log(1006, "内存分配失败");
        *count = 0;
        return NULL;
    }
    
    // 填充素数数组
    int index = 0;
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            primes[index++] = i;
        }
    }
    
    *count = prime_count;
    return primes;
}

int initialize_math_ops() {
    if (is_initialized) {
        debug_print("数学运算库已经初始化");
        return 1;
    }
    
    if (!initialize_utils()) {
        error_log(1007, "初始化工具库失败");
        return 0;
    }
    
    debug_print("数学运算库初始化成功");
    is_initialized = 1;
    return 1;
} 