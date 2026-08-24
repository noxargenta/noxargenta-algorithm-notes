# 异或找两个奇数次数 + Brian Kernighan

来源：[Two_Odd_Count_Numbers.cpp](../收藏模板题/Two_Odd_Count_Numbers.cpp) — 左程云视频 030_5

## 问题

数组 `nums` 中，只有 **两个数 a、b 出现奇数次**，其余所有数都出现偶数次。找出 a、b。

## 核心思想

### 1. 全体异或 → 得到 a ^ b

异或的性质：`x ^ x = 0`，`0 ^ x = x`。把数组全部异或一遍，出现偶数次的数全部抵消，剩下的就是 `eor1 = a ^ b`。

### 2. Brian Kernighan：提取最右侧的 1

`a != b`，所以 `eor1 = a ^ b != 0`，至少有一位是 1。**Brian Kernighan 算法**一步提取最右侧的 1：

```cpp
int rightOne = eor1 & (-eor1);
```

`-eor1` 是补码 = `~eor1 + 1`，与 `eor1` 相与后，除了最右侧的那个 1，其余位全为 0。

### 3. 按最右 1 分组

`rightOne` 这一位在 a 和 b 中**必然一个为 0、一个为 1**（因为它们是 a^b 中为 1 的位）。把数组中该位为 0 的数全部异或，得到的就是 a（或 b）本身：

```cpp
int eor2 = 0;
for (int num : nums) {
    if ((num & rightOne) == 0) {
        eor2 ^= num;
    }
}
// eor2 = a 或 b 中的某一个
```

另一个数 = `eor1 ^ eor2`。

## 完整代码

```cpp
pair<int, int> twoOddNumbers(vector<int>& nums) {
    int eor1 = 0;
    for (int num : nums) {
        eor1 ^= num;              // = a ^ b
    }

    int rightOne = eor1 & (-eor1); // Brian Kernighan：最右侧的 1

    int eor2 = 0;
    for (int num : nums) {
        if ((num & rightOne) == 0) {
            eor2 ^= num;          // = a 或 b
        }
    }

    int a = eor2;
    int b = eor1 ^ eor2;
    return {a, b};
}
```

## 复杂度

- 时间 O(n)，空间 O(1)

## 扩展

| 变体 | 做法 |
|------|------|
| 只有一个数出现奇数次 | 全体异或一次即可 |
| 两个数出现奇数次（本题） | 全体异或 → Brian Kernighan 分组 → 再异或 |
| k 个不同的数出现奇数次 | 按二进制位统计奇偶性（每个数的二进制位分别计数 % k） |

## 注意事项

- `a ^ b != 0` 是关键前提（a ≠ b），否则最右 1 不存在
- `rightOne` 分组的两组**只有一组包含 a 或 b**，另一组全是偶数次的数（会被抵消）
- 用 `int` 时 `-eor1` 即补码取负，C++ 中直接写 `eor1 & (-eor1)` 即可
