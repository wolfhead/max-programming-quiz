# Quiz 001: 下一个偶数

## 题目

给你一个整数 `inputA`，请返回严格大于 `inputA` 的最小偶数。

换句话说，答案必须满足：

- 是偶数。
- 比 `inputA` 大。
- 在所有满足条件的数里最小。

## 函数

```cpp
int quiz_1(int inputA);
```

## 输入

- `inputA`：一个整数，范围是 `-1000 <= inputA <= 1000`。

## 输出

返回严格大于 `inputA` 的最小偶数。

## 样例

```text
inputA = 3
return = 4
```

```text
inputA = 4
return = 6
```

## 目标能力

- 使用函数返回结果。
- 理解偶数。
- 使用 `%` 判断余数。
- 处理正数、负数和 0。

## 给学生的提示

如果 `inputA` 已经是偶数，答案不是它自己，而是下一个偶数。

## 本题命令

```bash
make compile
make submit
```

出题者可以使用：

```bash
make verify
```
