# BFS 常见错误与调试

来源：[蓝桥云课 走迷宫](../study/蓝桥云课%20走迷宫.cpp)

## 走迷宫正确实现

```cpp
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int G[300][300], vis[300][300], dist[300][300];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            if (G[i][j] == 0) vis[i][j] = 1;   // 墙直接当已访问
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;                     // !! 题目 1-based → 0-based

    queue<pair<int, int>> q;
    q.push({x1, y1});
    dist[x1][y1] = 0;
    vis[x1][y1] = 1;

    while (!q.empty()) {
        int xx = q.front().first, yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx2 = xx + dx[i];
            int yy2 = yy + dy[i];
            if (xx2 < 0 || xx2 >= n || yy2 < 0 || yy2 >= m) continue;  // !! 边界
            if (!vis[xx2][yy2]) {
                dist[xx2][yy2] = dist[xx][yy] + 1;
                if (xx2 == x2 && yy2 == y2) {
                    cout << dist[xx2][yy2] << endl;
                    return;
                }
                q.push({xx2, yy2});
                vis[xx2][yy2] = 1;               // !! 入队即标记
            }
        }
    }
    cout << -1 << endl;
}
```

## 三个经典坑

### 1. 下标不匹配：1-based 坐标没减 1

输入用 0 到 n-1 存地图，但题目给的起点终点是 1-based。

**现象**：数组越界、运行错误。

**错误**：`x1, y1` 直接入队，没有 `--`。

**改正**：读完坐标立刻减一。

```cpp
cin >> x1 >> y1 >> x2 >> y2;
x1--; y1--; x2--; y2--;
```

### 2. 缺少边界检查

BFS 向四周扩展时如果不判边界，会把越界坐标压进队列，之后取 `G[xx2][yy2]` 时访问未定义内存。

```cpp
// 错误：没用 continue 筛掉越界的
for (int i = 0; i < 4; i++) {
    int xx2 = xx + dx[i], yy2 = yy + dy[i];
    if (!vis[xx2][yy2]) { ... }   // xx2 可能是 -1 或 n
}

// 正确：先判边界
if (xx2 < 0 || xx2 >= n || yy2 < 0 || yy2 >= m) continue;
```

### 3. 未标记已访问 → 重复入队

入队时不立刻标 `vis`，同一个格子会被反复压进队列，复杂度爆炸。

```cpp
// 错误：先 push 后标 vis（顺序其实没错，但有人 push 完忘了写 vis）
q.push({xx2, yy2});
// vis[xx2][yy2] = 1;   ← 漏了这一行

// 正确习惯：push 和 vis 紧挨着写
q.push({xx2, yy2});
vis[xx2][yy2] = 1;
```

## 小优化：墙预处理

读地图时直接把墙 `0` 标为已访问，后续 BFS 无需额外判断 `a[i][j]`。

```cpp
if (G[i][j] == 0) vis[i][j] = 1;
```

这样扩展时只需 `if (!vis[xx2][yy2])`，不用再 `&& G[xx2][yy2] == 1`。
