# Programming Quiz

这个项目用于给刚开始学习 C++ 的初中生按 LeetCode 风格出题。

## 核心约定

- 一个 quiz 一个文件夹：`quizzes/quiz_001`、`quizzes/quiz_002`。
- 每个 quiz 目录是自包含的工作目录，可以被单独复制、编译和评测。
- 学生只修改每题目录下的 `student/solution.cpp`。
- 函数签名由题目决定，例如 `int quiz_1(int inputA)`。
- 每个 quiz 都提供 `make compile`、`make submit`、`make verify`。
- `make submit` 用学生解运行测试，并输出通过数、用时和内存。
- `make verify` 用同目录的参考解运行测试，用于出题者确认答案和数据无误。
- 参考解可以留在 `reference/solution.cpp`，学生正常只需要修改 `student/solution.cpp`。
- 根目录可以有公共代码库、工具链和模板，但学生做题不依赖根目录命令。

## 目录结构

```text
.
├── AGENTS.md
├── AUTHORING.md
├── README.md
├── quizzes
│   ├── quiz_001
│   │   ├── Makefile
│   │   ├── README.md
│   │   ├── include
│   │   │   └── quiz.hpp
│   │   ├── reference
│   │   │   └── solution.cpp
│   │   ├── student
│   │   │   └── solution.cpp
│   │   ├── tests
│   │   │   └── cases.txt
│   │   └── main.cpp
│   ├── quiz_002
│   │   ├── Makefile
│   │   ├── README.md
│   │   ├── include
│   │   │   └── quiz.hpp
│   │   ├── reference
│   │   │   └── solution.cpp
│   │   ├── student
│   │   │   └── solution.cpp
│   │   ├── tests
│   │   │   └── cases.txt
│   │   └── main.cpp
│   └── quiz_template
│       ├── Makefile
│       ├── README.md
│       ├── include
│       │   └── quiz.hpp
│       ├── reference
│       │   └── solution.cpp
│       ├── student
│       │   └── solution.cpp
│       ├── tests
│       │   └── cases.txt
│       └── main.cpp
└── progress
    └── README.md
```

## 出题流程

详细规范见 `AUTHORING.md`。

1. 复制 `quizzes/quiz_template` 为新的题目目录，例如 `quizzes/quiz_002`。
2. 修改 `README.md` 写题面、输入输出、样例和数学提示。
3. 修改 `include/quiz.hpp` 与 `student/solution.cpp` 中的函数签名。
4. 修改 `reference/solution.cpp` 写参考解。
5. 修改 `main.cpp` 读取测试数据并调用学生函数。
6. 修改 `tests/cases.txt` 写测试数据。
7. 在题目目录运行 `make verify`，确认参考解和测试数据正确。
8. 在题目目录运行 `make compile`，确认学生模板可以编译。
9. 在题目目录运行 `make submit`，确认学生提交流程可用。

## 学生使用方式

进入某个题目目录：

```bash
cd quizzes/quiz_001
make compile
make submit
```

学生完成 `student/solution.cpp` 后，如果所有测试通过，会看到：

```text
Verdict: Accepted
Passed: 12/12
Time: 0.123 ms
Memory: 1024 KB
```

## 难度与进度记录建议

每道题的 `README.md` 建议记录：

- 目标能力：变量、条件、循环、函数、数组、字符串等。
- 数学连接：算术、倍数、奇偶、数列、坐标、简单组合等。
- 预计难度：1 到 5。
- 学生完成情况：用额外的进度表或后续题目说明记录，不把临时结论写成长期规则。
