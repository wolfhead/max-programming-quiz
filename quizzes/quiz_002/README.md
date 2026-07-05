# Quiz 002: 数列的最大相邻差

## 题目

给你一个整数数组 `numbers`，请计算相邻两个数之间差的绝对值，并返回其中最大的一个。

例如数组是 `{3, 8, 6, 10}`：

- `3` 和 `8` 的差是 `5`
- `8` 和 `6` 的差是 `2`
- `6` 和 `10` 的差是 `4`

所以答案是 `5`。

## 函数

```cpp
int quiz_2(const std::vector<int>& numbers);
```

## 输入

- `numbers`：一个整数数组。
- 数组长度范围是 `2 <= numbers.size() <= 100`。
- 每个数字范围是 `-1000 <= numbers[i] <= 1000`。

## 输出

返回相邻两个数之间最大的绝对差。

## 样例

```text
numbers = {3, 8, 6, 10}
return = 5
```

```text
numbers = {-2, -7, 1}
return = 8
```

## 目标能力

- 使用 `std::vector<int>` 表示数组。
- 使用下标访问数组元素。
- 使用 `for` 循环遍历数组。
- 理解相邻元素。
- 理解差的绝对值。

## 给学生的提示

可以从第 2 个数开始看，每次比较 `numbers[i]` 和它前面的 `numbers[i - 1]`。

## 本题命令

```bash
make compile
make submit
```

出题者可以使用：

```bash
make verify
```
