# lower_bound / upper_bound 用法

二分查找的两个 STL 函数，有序序列上 O(log n)。

## 基本规则

| 函数 | 返回 | 条件 |
|------|------|------|
| `lower_bound(first, last, x)` | 第一个 **>= x** 的迭代器 | 升序序列 |
| `upper_bound(first, last, x)` | 第一个 **> x** 的迭代器 | 升序序列 |
| `lower_bound(first, last, x, greater<int>())` | 第一个 **<= x** 的迭代器 | 降序序列 |
| `upper_bound(first, last, x, greater<int>())` | 第一个 **< x** 的迭代器 | 降序序列 |

找不到时返回 `last`（end 迭代器）。

## 升序序列（默认）

```cpp
vector<int> a = {1, 3, 5, 5, 7, 9};

auto it = lower_bound(a.begin(), a.end(), 5);
// *it == 5, 指向第一个 5

auto it = upper_bound(a.begin(), a.end(), 5);
// *it == 7, 指向第一个 > 5 的元素

// 统计 x 出现次数
int cnt = upper_bound(a.begin(), a.end(), x) - lower_bound(a.begin(), a.end(), x);
```

## 降序序列（传 greater）

```cpp
vector<int> a = {9, 7, 5, 5, 3, 1};

auto it = lower_bound(a.begin(), a.end(), 5, greater<int>());
// *it == 5, 第一个 <= 5 的元素

auto it = upper_bound(a.begin(), a.end(), 5, greater<int>());
// *it == 3, 第一个 < 5 的元素
```

## LIS 系列应用（核心场景）

### 最长上升子序列 LIS

```cpp
vector<int> f;
for (auto x : a) {
    auto it = lower_bound(f.begin(), f.end(), x);
    if (it == f.end()) f.push_back(x);
    else *it = x;
}
// f.size() == LIS 长度
```

### 最长不下降子序列

```cpp
auto it = upper_bound(f.begin(), f.end(), x);   // 允许相等，所以用 upper
```

### 最长不上升子序列 LDS

```cpp
// 导弹拦截第一问：不升子序列
vector<int> f;
for (auto x : a) {
    auto it = upper_bound(f.begin(), f.end(), x, greater<int>());
    if (it == f.end()) f.push_back(x);
    else *it = x;
}
// f.size() == 最长不升子序列长度
```

### Dilworth 定理

最少的不升子序列覆盖数 = LIS 长度：

```cpp
// 导弹拦截第二问：最少需要多少套系统
vector<int> f;
for (auto x : a) {
    auto it = lower_bound(f.begin(), f.end(), x);   // 求 LIS
    if (it == f.end()) f.push_back(x);
    else *it = x;
}
// f.size() 就是答案
```

### LIS 四种变体速查

| 需求 | 写法 |
|------|------|
| 最长上升 (LIS) | `lower_bound(f.begin(), f.end(), x)` |
| 最长不降 | `upper_bound(f.begin(), f.end(), x)` |
| 最长下降 (LDS) | `lower_bound(f.begin(), f.end(), x, greater<int>())` |
| 最长不升 | `upper_bound(f.begin(), f.end(), x, greater<int>())` |

来自 [P_1020 导弹拦截](../study/P_1020_NOIP_1999_提高组_导弹拦截.cpp)。

## 统计区间内元素个数

在有序数组中统计某个值出现的次数：

```cpp
// f.cpp — 双指针枚举子集和 + 二分计数
int l = lower_bound(q.begin(), q.end(), tar) - q.begin();
int r = upper_bound(q.begin(), q.end(), tar) - q.begin();
int cnt = r - l;           // tar 在 q 中出现的次数
```

来自 [tiantisai/std/f.cpp](../tiantisai/std/f.cpp)。

## 坐标压缩

```cpp
vector<int> ls;
sort(ls.begin(), ls.end());
ls.erase(unique(ls.begin(), ls.end()), ls.end());

// 把原值映射到 1-based 索引
int idx = lower_bound(ls.begin(), ls.end(), val) - ls.begin() + 1;
```

来自 [MC0510 群臣功绩评定](../competition/2026matiji/MC0510%20群臣功绩评定copy.cpp)。

## set 自带的 lower_bound

`set` 有自己的 `lower_bound` 成员函数，O(log n) 树上二分，比 `std::lower_bound`（O(n)）快。

```cpp
set<int> s;
// 找到第一个 >= l 的元素，逐个删除 [l, r] 区间
auto it = s.lower_bound(l);
while (it != s.end() && *it <= r) {
    a[*it] = x;
    it = s.erase(it);       // erase 返回下一个迭代器
}
```

来自 [MC0448 诗词难度系数](../competition/2026matiji/MC0448%20诗词难度系数.cpp)。

## 在结构体数组上二分

```cpp
// 按 sum = x + w 排序后，二分找第一个 x - w 的位置
int idx = lower_bound(a.begin(), a.end(), array<int, 3>{x - w, INF, INF}) - a.begin();
```

来自 [tiantisai/std/h.cpp](../tiantisai/std/h.cpp)。

## 易错点

1. **必须有序** — 升序用默认比较器，降序必须传 `greater<int>()`
2. **找不到返回 end** — 用前检查 `it != v.end()`
3. **获取下标** — `lower_bound(...) - v.begin()`
4. **set 不要用 std::lower_bound** — `std::lower_bound(s.begin(), s.end(), x)` 是 O(n)，要用 `s.lower_bound(x)` O(log n)
