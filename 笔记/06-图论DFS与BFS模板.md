# 图论 DFS 与 BFS 模板

## 链式前向星（邻接表）

```cpp
vector<int> e[N];          // 无权图
vector<pair<int,int>> e[N]; // 带权图：e[u].push_back({v, w})

// 遍历
for (auto v : e[u]) { ... }
```

## 树上 DFS — 子树大小 & 深度

从 [P_9872_DFS_Order](../study/P_9872_DFS_Order.cpp) 和 [C_Minimum_Steiner_Tree](../competition/20251130ECUT11/C_Minimum_Steiner_Tree.cpp) 提炼：

```cpp
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

## BFS 网格搜索

从 [C_幅優先探索](../competition/20251130ECUT12/C_幅優先探索.cpp) 提炼：

```cpp
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dist[N][N];

queue<int> qx, qy;
qx.push(sx); qy.push(sy);
dist[sx][sy] = 0;

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

### 小技巧：用 pair 队列替代双队列

```cpp
queue<pair<int,int>> q;
q.push({sx, sy});
while (q.size()) {
    auto [x, y] = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (合法) {
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
}
```
