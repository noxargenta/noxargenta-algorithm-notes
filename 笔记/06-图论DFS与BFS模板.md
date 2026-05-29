# 图论 DFS 与 BFS 模板

## memset 初始化（BFS / DFS 前必备）

从 [P_1443 马的遍历](../study/P_1443_马的遍历.cpp) 提炼：

```cpp
bool vis[405][405];
int dis[405][405];

memset(vis, 0, sizeof(vis));    // 全部标记未访问
memset(dis, -1, sizeof(dis));   // 距离初始化为 -1（表示未到达）
```

> `memset` 按字节填充，只适用于 0 / -1 / 0x3f 等。vector 用 `fill` 或 `assign`。

---

## BFS — 马的遍历（8 方向 + queue<pair>）

从 [P_1443 马的遍历](../study/P_1443_马的遍历.cpp) 提炼：

```cpp
int n, m, x, y;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};   // 马走日
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool vis[405][405];
int dis[405][405];
queue<pair<int, int>> q;

void solve() {
    cin >> n >> m >> x >> y;
    x--; y--;                                   // 转换为 0-based
    memset(vis, 0, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    dis[x][y] = 0;
    vis[x][y] = 1;
    q.push({x, y});

    while (!q.empty()) {
        int xx = q.front().first;               // pair 取值方式
        int yy = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x2 = xx + dx[i];                // 用 x2/y2 避免和外层变量混淆
            int y2 = yy + dy[i];
            if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) continue;  // 边界判断
            if (!vis[x2][y2]) {
                vis[x2][y2] = 1;
                dis[x2][y2] = dis[xx][yy] + 1;
                q.push({x2, y2});
            }
        }
    }
    // 输出 dis 矩阵，-1 表示不可达
}
```

### 关键写法

| 要点 | 写法 |
|------|------|
| pair 队列 | `queue<pair<int,int>> q` → `q.push({x, y})` |
| 取首坐标 | `q.front().first` / `q.front().second` |
| memset 初值 | `-1` 表示不可达，`0` 表示未访问 |
| 边界判断 | `x2 < 0 \|\| x2 >= n \|\| y2 < 0 \|\| y2 >= m` |
| 避免变量遮蔽 | 用 `x2/y2` 而非内层重名 `x/y` |

---

## BFS 网格 4 方向 — 最短路径

从 [C_幅優先探索](../competition/20251130ECUT12/C_幅優先探索.cpp) 提炼：

```cpp
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<int> qx, qy;        // 双队列存坐标（老写法）

qx.push(sx); qy.push(sy);
while (qx.size()) {
    for (int i = 0; i < 4; i++) {
        int x = qx.front() + dx[i];
        int y = qy.front() + dy[i];
        if (x >= 1 && x <= n && y >= 1 && y <= m && 可通行) {
            qx.push(x); qy.push(y);
            dist[x][y] = dist[qx.front()][qy.front()] + 1;
            标记已访问;
        }
    }
    qx.pop(); qy.pop();
}
```

> 双队列现在建议统一用 `queue<pair<int,int>>`（P1443 风格），更简洁。

---

## DFS 洪水填充 (Flood Fill) — 8 方向

从 [P_1596 Lake Counting](../study/P_1596_USACO_10_OCT_Lake_Counting_S.cpp) 提炼：

数连通块个数：每个未访问的 'W' 触发一次 DFS，DFS 内遍历 8 方向传播。

```cpp
int n, m;
int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};  // 8 方向
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
char a[101][101];
bool vis[101][101];
int ans = 0;

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (a[nx][ny] == 'W' && !vis[nx][ny]) {
            dfs(nx, ny);
        }
    }
}
// 主函数中：
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (a[i][j] == 'W' && !vis[i][j]) {
            ans++;
            dfs(i, j);
        }
```

### 小技巧：vis 预处理

```cpp
// 陆地 '.' 直接标记为已访问，只在 'W' 上 DFS
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == '.') vis[i][j] = 1;
    }
```

---

## DFS — 不会被淹没的岛屿

从 [蓝桥云课 全球变暖](../study/蓝桥云课%20全球变暖.cpp) 提炼：

问题：四面环海的 `#` 会被淹没，统计不会被完全淹没的岛屿数。

核心思路：DFS 遍历岛屿时，检查是否存在**四面都不是 `.` 的 `#`**（即不会被淹没的地块）。

```cpp
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool gd = false;  // 全局标记：当前岛屿是否有不会被淹没的地块

void dfs(int x, int y) {
    vis[x][y] = 1;
    // 检查当前格子是否四面都不是水
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (a[nx][ny] == '.') flag = true;   // 有邻水 → 会被淹没
        }
    }
    if (!flag) gd = true;        // 四边没有水 → 不会淹没

    // 继续 DFS 遍历岛屿
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (!vis[nx][ny] && a[nx][ny] == '#') dfs(nx, ny);
    }
}
// 计数：只有 gd==false 的岛屿计入答案
```

---

## 树上 DFS — 子树大小 & 深度

从 [P_9872_DFS_Order](../study/P_9872_DFS_Order.cpp) 和 [C_Minimum_Steiner_Tree](../competition/20251130ECUT11/C_Minimum_Steiner_Tree.cpp) 提炼：

```cpp
vector<int> e[N];
int siz[N], dep[N];

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    siz[u] = 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
}
// 调用：dfs(1, 0);
```

---

## 方向数组速查

| 场景 | dx | dy |
|------|----|----|
| 4 方向（上下左右） | `{1,-1,0,0}` | `{0,0,1,-1}` |
| 8 方向（含对角线） | `{-1,0,1,0,1,1,-1,-1}` | `{0,1,0,-1,1,-1,1,-1}` |
| 马走日 | `{1,2,2,1,-1,-2,-2,-1}` | `{-2,-1,1,2,2,1,-1,-2}` |
