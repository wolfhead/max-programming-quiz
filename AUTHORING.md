# Authoring Guide

这份文档给未来的出题人使用。目标是让每道题都适合刚开始学习 C++ 的初中生，并保持类似 LeetCode 的提交体验。

## 设计原则

- 每道题只引入一个主要新能力。
- 题目优先连接数学直觉，例如奇偶、倍数、数列、坐标、图形、统计。
- 题面使用清楚的中文，避免竞赛黑话。
- 函数签名由题目决定，但参数数量要少，类型要稳定。
- 学生只需要修改 `student/solution.cpp`。
- 参考解可以保留在 `reference/solution.cpp`。
- 测试数据要覆盖样例、普通情况、边界情况和常见错误。

## Quiz 目录标准

每个 quiz 必须可以被单独复制和运行。

```text
quiz_xxx
├── Makefile
├── README.md
├── include
│   └── quiz.hpp
├── main.cpp
├── reference
│   └── solution.cpp
├── student
│   └── solution.cpp
└── tests
    └── cases.txt
```

## 必需命令

在每个 quiz 目录下必须支持：

```bash
make compile
make submit
make verify
make clean
```

- `make compile`：编译学生代码，不运行测试。
- `make submit`：运行学生代码，输出 Verdict、Passed、Time、Memory。
- `make verify`：运行参考解，确认参考解和测试数据一致。
- `make clean`：删除本题构建产物。

## 题面要求

每个 `README.md` 建议包含：

- 题目
- 函数
- 输入
- 输出
- 样例
- 目标能力
- 给学生的提示
- 本题命令

题面中的函数签名必须与 `include/quiz.hpp`、`student/solution.cpp`、`reference/solution.cpp` 完全一致。

## 测试数据要求

`tests/cases.txt` 的格式由每题的 `main.cpp` 决定。每个文件顶部必须写注释说明格式。

测试数据至少包含：

- 题面样例。
- 最小规模输入。
- 普通正数输入。
- 0 或负数输入，如果题目范围允许。
- 边界值输入。
- 容易写错的情况。

数组题建议包含：

- 长度为 2 的数组。
- 所有元素相同。
- 递增数组。
- 递减数组。
- 正负数混合。
- 最大值或最小值边界。

## 出题 Checklist

新增题目时按这个顺序做：

1. 复制 `quizzes/quiz_template` 为新目录。
2. 修改题号、题名和函数签名。
3. 写 `README.md`。
4. 写 `reference/solution.cpp`。
5. 写 `tests/cases.txt`。
6. 修改 `main.cpp` 的测试数据解析逻辑。
7. 修改根目录 `Makefile` 的 `QUIZZES`。
8. 运行新题目录下的 `make verify`。
9. 运行新题目录下的 `make compile`。
10. 运行新题目录下的 `make submit`，确认学生模板没有误通过。
11. 运行根目录 `make verify`。
12. 运行根目录 `make clean`。

## 难度规划

建议使用 1 到 5 级难度：

- 1：表达式、返回值、简单条件。
- 2：循环、取模、简单数学规则。
- 3：数组、字符串、累计、最大最小值。
- 4：嵌套循环、分类讨论、简单模拟。
- 5：需要组合多个概念或较强数学观察。

## 进度记录

学生完成一道题后，在 `progress/README.md` 或后续进度文件记录：

- 是否能独立读懂题目。
- 是否能说出算法思路。
- 是否能正确使用本题目标语法。
- 错误主要来自语法、边界、数学理解还是调试能力。
- 下一题应该巩固还是引入新概念。

这些记录用于后续出题节奏，不应该把一次临时表现写成长期判断。
