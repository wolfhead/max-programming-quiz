# Programming Quiz

这个项目用于给刚开始学习 C++ 的初中生按 LeetCode 风格出题。

## 核心约定

- 一个 quiz 一个文件夹：`quizzes/quiz_001`、`quizzes/quiz_002`。
- 学生只修改每题目录下的 `student/solution.cpp`。
- 函数签名由题目决定，例如 `int quiz_1(int inputA)`。
- 评测入口、测试数据、Makefile 由出题者维护。
- 最终交给学生时，可以只给题目目录里的题面、函数声明、学生模板、测试入口和测试数据，不包含参考答案。

## 目录结构

```text
.
├── AGENTS.md
├── README.md
├── quizzes
│   ├── quiz_001
│   │   ├── Makefile
│   │   ├── README.md
│   │   ├── include
│   │   │   └── quiz.hpp
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
│       ├── student
│       │   └── solution.cpp
│       ├── tests
│       │   └── cases.txt
│       └── main.cpp
└── tools
    └── verify_quiz_001_reference.cpp
```

## 出题流程

1. 复制 `quizzes/quiz_template` 为新的题目目录，例如 `quizzes/quiz_002`。
2. 修改 `README.md` 写题面、输入输出、样例和数学提示。
3. 修改 `include/quiz.hpp` 与 `student/solution.cpp` 中的函数签名。
4. 修改 `main.cpp` 读取测试数据并调用学生函数。
5. 修改 `tests/cases.txt` 写测试数据。
6. 用参考实现本地验证测试数据正确，再删除或不要交付参考实现。
7. 在题目目录运行 `make test`，确认评测入口能正常工作。

## 学生使用方式

进入某个题目目录：

```bash
cd quizzes/quiz_001
make test
```

学生完成 `student/solution.cpp` 后，如果所有测试通过，会看到：

```text
All tests passed.
```

## 难度与进度记录建议

每道题的 `README.md` 建议记录：

- 目标能力：变量、条件、循环、函数、数组、字符串等。
- 数学连接：算术、倍数、奇偶、数列、坐标、简单组合等。
- 预计难度：1 到 5。
- 学生完成情况：用额外的进度表或后续题目说明记录，不把临时结论写成长期规则。
