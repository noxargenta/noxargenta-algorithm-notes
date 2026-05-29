# 算法竞赛学习记录

个人算法竞赛训练仓库，涵盖从入门语法到竞赛算法的完整学习路径。包含日常练习、比赛训练与模板整理。

---

## 快速导航

| 板块 | 说明 |
|------|------|
| [学习路径](#学习路径) | 按算法分类的代码索引，标注了每个知识点对应的练习 |
| [目录概览](#目录概览) | 仓库物理结构说明 |
| [训练记录](#训练记录) | 按时间线的比赛/训练索引 |
| [模板收藏](#模板收藏) | 经典模板题汇总 |
| [套路总结](#套路总结) | 常用写法和小技巧 |

---

## 学习路径

按算法竞赛常见的学习顺序组织。

### 阶段一：基础语法与输入输出

<details>
<summary>语法基础、STL 入门、暴力枚举</summary>

| 知识点 | 练习代码 | 位置 |
|-------|---------|------|
| 基本输入输出 | `A_.../B_.../C_...` | [study/10.1](./study/10.1)、[study/10.2](./study/10.2) |
| 条件判断、循环 | `a.cpp` ~ `f.cpp` | [study/10.4](./study/10.4) |
| 数组操作 | `a.cpp` ~ `f.cpp` | [study/10.5](./study/10.5)、[study/10.7](./study/10.7) |
| String 处理 | `B_4012_语言月赛_202407_rules.cpp` | [study/](./study) |
| 暴力枚举 | `P_1428_小鱼比可爱.cpp`、`luoguP1008.cpp` | [study/](./study) |

</details>

### 阶段二：差分与前缀和

<details>
<summary>一维/二维差分、前缀和技巧</summary>

| 知识点 | 练习代码 | 位置 |
|-------|---------|------|
| 二维前缀和与差分 | 专题训练 | [study/11.5(二维前缀和差分, 链表, 图的存储, 并查集, 堆)](./study/11.5(二维前缀和差分,%20链表,%20图的存储,%20并查集,%20堆)) |
| 差分数组区间修改 | `Meximum_Array_2.cpp` — 差分经典写法 `d1[l]++` `d1[r+1]--` | [study/CF 1066(div1+2)](./study/CF%201066(div1+2)) |
| 前缀和统计 | 日常练习 | [study/2025.10.20](./study/2025.10.20) |

</details>

### 阶段三：二分查找与二分答案

<details>
<summary>二分搜索、二分答案 + check 函数</summary>

| 知识点 | 练习代码 | 位置 |
|-------|---------|------|
| 二分答案 + 区间可行性 | `D_Jumping_Through_Segments.cpp` — 二分移动次数，check 里维护可达区间 | [competition/20251120ECUT计协第六次训练赛](./competition/20251120ECUT计协第六次训练赛) |
| 二分 + 差分 | `C_租借教室.cpp` — 二分订单数，差分判断 | [competition/20251123ECUT计协第七次训练赛](./competition/20251123ECUT计协第七次训练赛) |
| 二分 + 贪心 | `D_劫富济贫.cpp` — 中位数 + 平均数的二分思路 | [competition/20251123ECUT计协第七次训练赛](./competition/20251123ECUT计协第七次训练赛) |

</details>

### 阶段四：双指针与滑动窗口

<details>
<summary>同向/相向双指针、滑动窗口</summary>

| 知识点 | 练习代码 | 位置 |
|-------|---------|------|
| 双指针维护合法区间 | `d.cpp` — 累加 sum 超出 r 时收缩左指针，经典滑窗计数 | [competition/20251110ECUT计协第四次训练赛](./competition/20251110ECUT计协第四次训练赛) |
| 滑动窗口最小值/最大值 | `P_1886_滑动窗口_模板_单调队列.cpp` — **deque 维护下标，O(n) 经典模板** | [study/](./study) |
| 双指针去重统计 | `J_Range_Replace.cpp` — 排序后滑窗计数贡献 | [competition/20251214ECUT10](./competition/20251214ECUT10) |

</details>

### 阶段五：栈与单调栈

<details>
<summary>单调栈（Next Greater Element）</summary>

| 知识点 | 练习代码 | 位置 |
|-------|---------|------|
| 单调栈模板 | `P_5788_模板_单调栈.cpp` — **逆序遍历，单调递减栈 O(n)** | [study/](./study) |
| 单调栈应用 | 各种涉及"右边第一个大于/小于"的题目 | 各比赛 |

</details>

### 阶段六：排序与贪心

<details>
<summary>排序 + 贪心策略</summary>

| 知识点 | 练习代码 | 位置 |
|-------|---------|------|
| 排序 + 枚举 | `A_Unique_Number.cpp` | [competition/20251130ECUT计协第八次训练赛](./competition/20251130ECUT计协第八次训练赛) |
| 贪心构造 | `B_Jumps.cpp` — 数学 + 贪心跳步 | [competition/20251130ECUT计协第八次训练赛](./competition/20251130ECUT计协第八次训练赛) |
| 贪心 + 前缀最大值 | `Block_Game.cpp` — 相邻和最大 | [competition/2026.2.3NEWK1](./competition/2026.2.3NEWK1) |
| 贪心 + 排序 | `I_EKIPA.cpp` — 按最大值排序取 top-k | [competition/20251207ECUT9](./competition/20251207ECUT9) |

</details>

### 阶段七：搜索（DFS / BFS）

<details>
<summary>深度优先搜索、广度优先搜索、树上的 DFS</summary>

| 知识点 | 练习代码 | 位置 |
|-------|---------|------|
| BFS 网格搜索 | `C_幅優先探索.cpp` — **双队列存坐标，经典 BFS 模板** | [competition/20251130ECUT12](./competition/20251130ECUT12) |
| BFS 马走日 | `P_1443_马的遍历.cpp` — **queue<pair> + memset 初始化 + 8 方向** | [study/](./study) |
| BFS 最短路径 | `蓝桥云课 走迷宫.cpp` — **BFS 四方向走迷宫基础模板** | [study/](./study) |
| DFS 洪水填充 (8 方向) | `P_1596_Lake_Counting.cpp` — **Flood Fill 数连通块** | [study/](./study) |
| DFS 岛屿淹没 | `蓝桥云课 全球变暖.cpp` — **检查四面是否邻水判断是否淹没** | [study/](./study) |
| Valid BFS 序验证 | `CF_1037_D_Valid_BFS.cpp` — **邻接表按 BFS 序排序后验证** | [study/](./study) |
| BFS 序 | `K_BFS序.cpp` | [competition/2025.12.29group4](./competition/2025.12.29group4) |
| DFS 序 | `P_9872_DFS_Order.cpp` — **DFS 遍历树，记录 depth 和子树大小** | [study/](./study) |
| DFS 搜索 | `MC0456(DFS)斩断灵根.cpp` | [收藏模板题](./收藏模板题) |
| 回溯搜索 | `MC0509 快刀乱麻定局.cpp` | [收藏模板题](./收藏模板题) |

</details>

### 阶段八：图论基础

<details>
<summary>图的存储、树的遍历、拓扑排序</summary>

| 知识点 | 练习代码 | 位置 |
|-------|---------|------|
| 邻接表存图 | 专题训练 | [study/11.5](./study/11.5(二维前缀和差分,%20链表,%20图的存储,%20并查集,%20堆)) |
| 树上 DFS（子树大小 + 深度） | `C_Minimum_Steiner_Tree.cpp` — **DFS 标记关键点子树，双向遍历** | [competition/20251130ECUT11](./competition/20251130ECUT11) |
| 最短路 / 01-BFS | `B_Toggle_Maze.cpp` | [competition/20251130ECUT11](./competition/20251130ECUT11) |
| Floyd | `D_Development.cpp` (优化) | 各比赛 |
| 拓扑排序 | 图论基础训练 | 各比赛 |

</details>

### 阶段九：并查集（DSU）

<details>
<summary>并查集、带权并查集、扩展域</summary>

| 知识点 | 练习代码 | 位置 |
|-------|---------|------|
| DSU 判环 | `F_Cow_and_Snacks.cpp` — **路径压缩 `f[x]==x? x:f[x]=find(f[x])`** | [competition/20251130ECUT12](./competition/20251130ECUT12) |
| 扩展域 DSU（敌人关系） | `K_团伙.cpp` — **`merge(x+n,y)` 处理敌人的敌人是朋友** | [competition/20251207ECUT9](./competition/20251207ECUT9) |

</details>

### 阶段十：数学与数论

<details>
<summary>质因数分解、GCD/LCM、组合数学、位运算</summary>

| 知识点 | 练习代码 | 位置 |
|-------|---------|------|
| 质数判定 O(√n) | `P_1036_..._选数.cpp` — **`isPrime()` 试除模板** | [study/](./study) |
| 欧拉线性筛 O(N) | `P_1036_..._选数 copy.cpp` — **bitset + 欧拉筛，每次 O(1) 查表** | [study/](./study) |
| 质因数分解 | `c.cpp` (2025ECPC) — **试除 O(√n) 模板** | [competition/2025ECPC](./competition/2025ECPC) |
| 位运算 | `x_y_n.cpp` — 移位 `n<<31` | [competition/2026.2.5NEWK2](./competition/2026.2.5NEWK2) |
| 计数 + 组合数学 | `Card_Game.cpp` — **MOD 阶乘计数** | [competition/2026.2.3NEWK1](./competition/2026.2.3NEWK1) |
| 数学结论 | `Jumps.cpp` — **等差数列求和 + 修正** | [competition/20251130ECUT计协第八次训练赛](./competition/20251130ECUT计协第八次训练赛) |
| 位运算 + 构造 | `NCPC.cpp` — bit 计数判胜负 | [competition/2026.2.5NEWK2](./competition/2026.2.5NEWK2) |
| 三分/几何 | `E_Closest_Moment` | 各比赛 |

</details>

### 阶段十一：动态规划

<details>
<summary>线性 DP、背包 DP、树形 DP</summary>

| 知识点 | 练习代码 | 位置 |
|-------|---------|------|
| 线性 DP | 各比赛中级题目 | 各比赛 |
| 背包 DP | ECUT 训练赛题目 | 各比赛 |
| 树形 DP | DSU on tree、树上 DFS 类 | 各比赛 |
| 计数 DP | 计数类题目 | 各比赛 |

</details>

### 阶段十二：数据结构进阶

<details>
<summary>线段树、树状数组、ST 表</summary>

| 知识点 | 练习代码 | 位置 |
|-------|---------|------|
| 树状数组 | 专题训练 | 各比赛 |
| 线段树 | 各比赛中高级题目 | 各比赛 |
| 优先队列 | STL 混战专题 | [competition/stl-hunzhan](./competition/stl-hunzhan) |

</details>

---

## 目录概览

| 目录 | 说明 |
|------|------|
| [study/](./study) | **日常学习** — 按日期/主题组织的练习题，含洛谷、CF、AtCoder 等平台题目 |
| [competition/](./competition) | **比赛训练** — ECUT 计协训练赛、ECPC 江西省赛、NewCode、牛客周赛等 |
| [tiantisai/](./tiantisai) | **天梯赛专题** — 含个人解法与 std 标准参考 |
| [收藏模板题/](./收藏模板题) | **经典模板** — 并查集、DFS、BFS 等收藏题目 |

---

## 训练记录

### ECUT 计协训练赛

| 时间 | 赛事 | 链接 |
|------|------|------|
| 2025.10 | 记协第一次训练赛 | [competition/记协第一次训练赛](./competition/记协第一次训练赛) |
| 2025.10 | 计算机协会第二次 | [competition/计算机协会第二次](./competition/计算机协会第二次) |
| 2025.11 | ECUT 计协第四次训练赛 | [competition/20251110ECUT计协第四次训练赛](./competition/20251110ECUT计协第四次训练赛) |
| 2025.11 | ECUT 计协第五次训练赛 | [competition/20251115ECUT计协第五次训练赛](./competition/20251115ECUT计协第五次训练赛) |
| 2025.11 | ECUT 计协第六次训练赛 | [competition/20251120ECUT计协第六次训练赛](./competition/20251120ECUT计协第六次训练赛) |
| 2025.11 | ECUT 计协第七次训练赛 | [competition/20251123ECUT计协第七次训练赛](./competition/20251123ECUT计协第七次训练赛) |
| 2025.11 | ECUT 计协第八次训练赛 | [competition/20251130ECUT计协第八次训练赛](./competition/20251130ECUT计协第八次训练赛) |
| 2025.11 | ECUT 训练赛 11 | [competition/20251130ECUT11](./competition/20251130ECUT11) |
| 2025.11 | ECUT 训练赛 12 | [competition/20251130ECUT12](./competition/20251130ECUT12) |
| 2025.12 | ECUT 训练赛 9 | [competition/20251207ECUT9](./competition/20251207ECUT9) |
| 2025.12 | ECUT 训练赛 10 | [competition/20251214ECUT10](./competition/20251214ECUT10) |

### 校外比赛与训练

| 时间 | 赛事 | 链接 |
|------|------|------|
| 2024 | ECUT 新生赛 | [competition/2024ECUT](./competition/2024ECUT) |
| 2025.10 | NCHU 训练赛 | [competition/2025.10.15NCHU](./competition/2025.10.15NCHU) |
| 2025.10 | 牛客训练 | [competition/niuke2025.10.12](./competition/niuke2025.10.12) |
| 2025.11 | 第三次训练赛 | [competition/2025.11.2第三次训练赛](./competition/2025.11.2第三次训练赛) |
| 2025.11 | CF 1066(div1+2) 补题 | [study/CF 1066(div1+2)](./study/CF%201066(div1+2)) |
| 2025.11 | Pinely Round 5 补题 | [study/Pinely Round 5 (Div. 1 + Div. 2)](./study/Pinely%20Round%205%20(Div.%201%20+%20Div.%202)) |
| 2025.11 | 组队训练 | [competition/2025.11.11](./competition/2025.11.11) |
| 2025.12 | 组队训练 group4 | [competition/2025.12.29group4](./competition/2025.12.29group4) |
| 2025.12 | 组队训练 12.16 | [competition/group4 2025.12.16](./competition/group4%202025.12.16) |
| 2025 | 江西省赛 ECPC | [competition/2025ECPC](./competition/2025ECPC) |
| 2025 | 码蹄集训练 | [competition/2025matiji111](./competition/2025matiji111) |
| 2026.02 | NewCode K1 | [competition/2026.2.3NEWK1](./competition/2026.2.3NEWK1) |
| 2026.02 | NewCode K2 | [competition/2026.2.5NEWK2](./competition/2026.2.5NEWK2) |
| 2026.02 | NewCode K3 | [competition/2026.2.7NEWK3](./competition/2026.2.7NEWK3) |
| 2026.02 | NewCode K4 | [competition/2026.2.9NEWK4](./competition/2026.2.9NEWK4) |
| 2026 | 码蹄集（第二阶段） | [competition/2026matiji](./competition/2026matiji) |
| 2026 | 码蹄集比赛 | [competition/2026matijicomepition](./competition/2026matijicomepition) |
| 2026.03 | 天梯赛训练 | [tiantisai](./tiantisai) |
| — | AtCoder ABC | [competition/ATC436](./competition/ATC436) |
| — | CF Round 1090 (Div. 4) | [study/Codeforces Round 1090 (Div. 4)](./study/Codeforces%20Round%201090%20(Div.%204)) |
| — | 牛客周赛 | [competition/牛客周赛 Round 114](./competition/牛客周赛%20Round%20114) |
| — | 传智杯 | [competition/传智杯](./competition/传智杯) |

### STL 专题混战

| 专题 | 链接 |
|------|------|
| STL 综合应用 | [competition/stl-hunzhan](./competition/stl-hunzhan) |

---

## 模板收藏

| 题目 | 算法 | 位置 |
|------|------|------|
| F_Cow_and_Snacks | DSU 并查集判环 + 路径压缩 | [收藏模板题](./收藏模板题/F_Cow_and_Snacks.cpp) |
| K_团伙 | 扩展域并查集（敌人关系） | [competition/20251207ECUT9](./competition/20251207ECUT9/K_团伙.cpp) |
| Valid BFS | BFS 序验证 | [收藏模板题](./收藏模板题/Valid%20BFS.cpp) |
| MC0456(DFS)斩断灵根 | DFS 搜索 | [收藏模板题](./收藏模板题/MC0456(DFS)斩断灵根.cpp) |
| MC0509 快刀乱麻定局 | 回溯搜索 | [收藏模板题](./收藏模板题/MC0509%20快刀乱麻定局.cpp) |
| P_1443 马的遍历 | BFS queue<pair> + memset | [study/](./study/P_1443_马的遍历.cpp) |
| 蓝桥云课 走迷宫 | BFS 走迷宫完整模板 | [study/](./study/蓝桥云课%20走迷宫.cpp) |
| P_1596 Lake Counting | DFS Flood Fill 8 方向 | [study/](./study/P_1596_USACO_10_OCT_Lake_Counting_S.cpp) |
| 蓝桥云课 全球变暖 | DFS 岛屿淹没判定 | [study/](./study/蓝桥云课%20全球变暖.cpp) |
| P_1886 滑动窗口 | 单调队列（deque） | [study/](./study/P_1886_滑动窗口_模板_单调队列.cpp) |
| P_5788 单调栈 | 单调栈 NGE | [study/](./study/P_5788_模板_单调栈.cpp) |
| P_9872 DFS Order | DFS 序 + 子树大小 | [study/](./study/P_9872_DFS_Order.cpp) |
| C_幅優先探索 | BFS 网格搜索 | [competition/20251130ECUT12](./competition/20251130ECUT12/C_幅優先探索.cpp) |
| C_Minimum_Steiner_Tree | 树上 DFS 标记 + 剪枝 | [competition/20251130ECUT11](./competition/20251130ECUT11/C_Minimum_Steiner_Tree.cpp) |

---

## 套路总结

常用写法汇总。

### 1. 基础模板

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long

void solve() {
    // your code here
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}
```

### 2. 单调队列 — 滑窗最值 (deque 存下标)

```cpp
deque<int> q;
for(int i = 0; i < n; i++) {
    if(!q.empty() && q.front() <= i - k) q.pop_front();
    while(!q.empty() && a[q.back()] >= a[i]) q.pop_back();
    q.push_back(i);
    if(i >= k - 1) cout << a[q.front()] << " ";
}
```

### 3. 单调栈 — 右边第一个更大

```cpp
stack<int> s;
for(int i = n; i >= 1; i--) {
    while(!s.empty() && a[i] >= a[s.top()]) s.pop();
    ans[i] = s.empty() ? 0 : s.top();
    s.push(i);
}
```

### 4. DSU 路径压缩 (一行版)

```cpp
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
```

### 5. 扩展域 DSU — 敌人的敌人是朋友

```cpp
merge(x + n, y);
merge(y + n, x);
```

### 6. 二分答案 — 区间可行性 check

```cpp
bool check(int k) {
    int L = 0, R = 0;
    for(int i = 1; i <= n; i++) {
        L -= k; R += k;
        if(L > r[i] || R < l[i]) return false;
        L = max(L, l[i]);
        R = min(R, r[i]);
    }
    return true;
}
```

### 7. 差分数组

```cpp
diff[l] += val;
diff[r + 1] -= val;
for(int i = 1; i <= n; i++) diff[i] += diff[i - 1];
```

### 8. 双指针 — 统计合法区间

```cpp
int j = 0; i64 sum = 0;
for(int i = 0; i < n; i++) {
    sum += a[i];
    while(sum > r && j <= i) {
        sum -= a[j]; j++;
    }
    if(sum >= l && sum <= r) {
        ans++;
        sum = 0; j = i + 1;
    }
}
```

### 9. BFS (queue<pair> + 走迷宫三坑：下标/边界/标记)

```cpp
bool vis[405][405]; int dis[405][405];
memset(vis, 0, sizeof(vis));
memset(dis, -1, sizeof(dis));          // -1 表示不可达
queue<pair<int, int>> q;
q.push({x, y}); vis[x][y] = 1; dis[x][y] = 0;

while (!q.empty()) {
    int xx = q.front().first;
    int yy = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
        int x2 = xx + dx[i];
        int y2 = yy + dy[i];
        if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) continue;
        if (!vis[x2][y2]) {
            vis[x2][y2] = 1;
            dis[x2][y2] = dis[xx][yy] + 1;
            q.push({x2, y2});
        }
    }
}
```

**三个坑**：
1. 题目坐标是 1-based，读入后必须 `x1--; y1--; x2--; y2--;`
2. 扩展前要先判 `x2<0||x2>=n||y2<0||y2>=m`，否则数组越界
3. `push` 后立刻 `vis=1`，漏了会死循环

### 10. 常用 INF / 哨兵值

```cpp
const int INF = 0x7f7f7f7f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;
int maxx = -0x7f7f7f7f;
```

### 11. 邻接表排序 (按 BFS 序)

```cpp
sort(tu[i].begin(), tu[i].end(), [&](int x, int y) {
    return pos[x] < pos[y];
});
```

### 12. DFS Flood Fill（8 方向数连通块）

```cpp
int dx[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (a[nx][ny] == 'W' && !vis[nx][ny]) dfs(nx, ny);
    }
}
// 外部计数：每个未访问的 'W' 触发 dfs，ans++
```

### 13. 方向数组速查

| 场景 | dx | dy |
|------|----|----|
| 4 方向（上下左右） | `{1,-1,0,0}` | `{0,0,1,-1}` |
| 8 方向（含对角线） | `{-1,0,1,0,1,1,-1,-1}` | `{0,1,0,-1,1,-1,1,-1}` |
| 马走日 | `{1,2,2,1,-1,-2,-2,-1}` | `{-2,-1,1,2,2,1,-1,-2}` |

### 14. 欧拉线性筛 (bitset + 最小质因子)

```cpp
const int N = 100000008;
bitset<N> c;
c.set(); c[0] = c[1] = 0;
vector<int> primes;
for (int i = 2; i < N; i++) {
    if (c[i]) primes.push_back(i);
    for (auto x : primes) {
        if (x * i >= N) break;
        c[x * i] = 0;
        if (i % x == 0) break;
    }
}
// c[x] == 1 表示 x 是质数，O(1) 查表
```
