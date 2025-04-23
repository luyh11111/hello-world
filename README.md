# C语言函数调用关系演示

这是一个演示C语言函数调用关系的示例工程，专为与C Relation插件一起使用而设计。

## 项目结构

```
.
├── include/             # 头文件目录
│   ├── utils.h          # 实用工具函数接口
│   ├── math_ops.h       # 数学运算函数接口
│   ├── string_ops.h     # 字符串处理函数接口
│   └── file_ops.h       # 文件操作函数接口
├── src/                 # 源文件目录
│   ├── utils.c          # 实用工具函数实现
│   ├── math_ops.c       # 数学运算函数实现
│   ├── string_ops.c     # 字符串处理函数实现
│   └── file_ops.c       # 文件操作函数实现
├── main.c               # 主程序入口
├── Makefile             # 构建脚本
└── README.md            # 项目说明
```

## 功能模块

1. **utils** - 实用工具函数（调试输出、错误日志、时间戳等）
2. **math_ops** - 数学运算函数（加减乘除、阶乘、斐波那契数列等）
3. **string_ops** - 字符串处理函数（复制、连接、转换、查找等）
4. **file_ops** - 文件操作函数（读写、复制、移动、删除等）

## 函数调用关系

- **main** 函数调用各个模块的初始化函数和测试函数
- **math_ops** 函数调用 **utils** 函数进行调试和错误处理
- **string_ops** 函数调用 **utils** 函数进行调试和错误处理
- **file_ops** 函数调用 **utils** 和 **string_ops** 函数

## 使用C Relation插件分析

1. 打开命令面板（Ctrl+Shift+P）
2. 输入并选择 "C Relation: Init database" 初始化数据库
3. 选择任意函数名（例如 `main`）
4. 右键选择 "Show Relations" 查看函数调用关系

## 构建和运行

```bash
# 构建项目
make

# 运行项目
./program

# 查看帮助
./program --help

# 清理项目
make clean
```

## 命令行选项

- `--help`, `-h` - 显示帮助信息
- `--math` - 仅运行数学函数测试
- `--string` - 仅运行字符串函数测试
- `--file` - 仅运行文件函数测试
- `--add X Y` - 计算X+Y的结果
- `--factorial N` - 计算N的阶乘

## 项目特点

- 丰富的函数调用关系
- 多层模块依赖
- 内置的测试和演示功能
- 完整的代码文档和注释
- 适合作为C Relation插件的演示项目