# 线性 DP：LIS 与网格路径

来源：[P_1091_NOIP_2004_提高组_合唱队形](../study/P_1091_NOIP_2004_提高组_合唱队形DP解决.cpp) / [P_1020_NOIP_1999_提高组_导弹拦截](../study/P_1020_NOIP_1999_提高组_导弹拦截.cpp) / [P_1002_NOIP_2002_普及组_过河卒](../study/P_1002_NOIP_2002_普及组_过河卒.cpp)

## LIS（最长上升子序列）

### O(n²) 基础 DP

`dp[i]` = 以 a[i] 结尾的 LIS 长度。

```cpp
for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i])
            dp[i] = max(dp[i], dp[j] + 1);
    }
}
```

### 双向 LIS（合唱队形）

求"先升后降"的最长子序列：正着跑一次 LIS（`dp1`），反着跑一次 LIS（`dp2`），以 i 为峰值的长度 = `dp1[i] + dp2[i] - 1`。

```cpp
// 正向 LIS
for (int i = 0; i < n; i++) {
    dp1[i] = 1;
    for (int j = 0; j < i; j++)
        if (a[j] < a[i]) dp1[i] = max(dp1[i], dp1[j] + 1);
}
// 反向 LIS
for (int i = n - 1; i >= 0; i--) {
    dp2[i] = 1;
    for (int j = n - 1; j > i; j--)
        if (a[j] < a[i]) dp2[i] = max(dp2[i], dp2[j] + 1);
}
// 合并
int len = 0;
for (int i = 0; i < n; i++)
    len = max(len, dp1[i] + dp2[i] - 1);
cout << n - len << endl;   // 最少出列人数
```

### O(n log n) 贪心 + 二分

维护数组 `f`，`f[i]` = 长度为 i+1 的上升子序列的最小末尾值。

```cpp
vector<int> f;
for (auto x : a) {
    auto it = lower_bound(f.begin(), f.end(), x);
    if (it == f.end())
        f.push_back(x);
    else
        *it = x;
}
// f.size() 就是 LIS 长度
```

### 最长不升子序列（导弹拦截）

求 LDS（最长不升子序列），用 `upper_bound` + `greater<int>()`：

```cpp
vector<int> f;
for (auto x : h) {
    auto it = upper_bound(f.begin(), f.end(), x, greater<int>());
    if (it == f.end())
        f.push_back(x);
    else
        *it = x;
}
cout << f.size() << endl;   // 第一问：最长不升子序列长度
```

第二问（Dilworth 定理）：最少的不升子序列覆盖数 = LIS 长度。

```cpp
vector<int> f2;
for (auto x : h) {
    auto it = lower_bound(f2.begin(), f2.end(), x);
    if (it == f2.end())
        f2.push_back(x);
    else
        *it = x;
}
cout << f2.size() << endl;   // 第二问：需要多少套系统
```

**Dilworth 定理**：偏序集的最少链覆盖数 = 最长反链长度。对导弹拦截来说，最少的不升子序列个数 = 最长上升子序列长度。

### LIS 速查

| 需求 | 写法 |
|------|------|
| 最长上升 (LIS) | `lower_bound(f.begin(), f.end(), x)` |
| 最长不降 | `upper_bound(f.begin(), f.end(), x)` |
| 最长下降 (LDS) | `lower_bound(f.begin(), f.end(), x, greater<int>())` |
| 最长不升 | `upper_bound(f.begin(), f.end(), x, greater<int>())` |

## 网格路径 DP（过河卒）

从 (0,0) 走到 (n,m)，只能向右或向下，马挡在 (x,y) 及其攻击范围。

`dp[i][j]` = 到达 (i,j) 的路径数。

```cpp
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};   // 马走日攻击范围
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool block[N][N];                              // 阻挡标记

// 标记马的位置和攻击范围
block[x][y] = 1;
for (int i = 0; i < 8; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx >= 0 && yy >= 0) block[xx][yy] = 1;
}

// DP
dp[0][0] = 1;
for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
        if (block[i][j]) { dp[i][j] = 0; continue; }
        if (i > 0) dp[i][j] += dp[i-1][j];
        if (j > 0) dp[i][j] += dp[i][j-1];
    }
}
cout << dp[n][m] << endl;
```

递推公式：`dp[i][j] = dp[i-1][j] + dp[i][j-1]`（只能向右向下时的经典公式）。
