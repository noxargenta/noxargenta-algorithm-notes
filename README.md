# 算法竞赛学习记录

个人算法竞赛训练仓库，涵盖从入门语法到竞赛算法的完整学习路径。有练过的标注文件位置，还没学的标 **无**，方便查漏补缺。

---

## 快速导航

| 板块 | 说明 |
|------|------|
| [📖 学习路径](#-学习路径) | 完整算法知识体系 + 你的练习索引 |
| [📁 目录概览](#-目录概览) | 仓库物理结构说明 |
| [🏆 训练记录](#-训练记录) | 按时间线的比赛/训练索引 |
| [📌 模板收藏](#-模板收藏) | 经典模板题汇总 |
| [⚡ 你代码里的套路总结](#-你代码里的套路总结) | 从你的代码中提炼的常用写法 |

---

## 📖 学习路径

完整算法竞赛知识体系。**路径** = 有练习代码；**无** = 还没学，可作为后续学习清单。

---

### 一、语言基础

<details open>
<summary>C++ 语法基础与 STL</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 基本数据类型、输入输出 | ✅ | [study/10.1](./study/10.1)、[study/10.2](./study/10.2) |
| 分支与循环 | ✅ | [study/10.4](./study/10.4) |
| 数组与字符串 | ✅ | [study/10.5](./study/10.5)、[study/10.7](./study/10.7) |
| 函数与递归 | ✅ | 各文件均有 |
| `vector` | ✅ | 频繁使用 |
| `stack` / `queue` / `deque` | ✅ | [单调栈](./study/P_5788_模板_单调栈.cpp)、[单调队列](./study/P_1886_滑动窗口_模板_单调队列.cpp) |
| `set` / `map` / `unordered_map` | ✅ | [MC0438 姓名分数](./competition/2026matiji/MC0438%20姓名分数.cpp) 等 |
| `string` | ✅ | 多文件使用 |
| `pair` / `tuple` | ✅ | 各比赛 |
| `algorithm` 库 (sort, reverse, etc.) | ✅ | 各比赛 |
| `bitset` | 无 | — |
| `functional` (lambda 表达式) | ✅ | [CF_1037_D](./study/CF_1037_D_Valid_BFS.cpp) — sort 自定义比较 |

</details>

---

### 二、基础算法

<details open>
<summary>枚举、模拟、递归、分治</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 暴力枚举 | ✅ | [P_1428](./study/P_1428_小鱼比可爱.cpp)、[P_1008](./study/luoguP1008.cpp) |
| 模拟 | ✅ | 多个比赛题 |
| 递归 | ✅ | DFS、DSU 等均有 |
| 分治 | 无 | 归并排序、CDQ 分治等 |

</details>

<details open>
<summary>前缀和与差分</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 一维前缀和 | ✅ | 多文件使用 |
| 一维差分 | ✅ | [Meximum_Array_2](./study/CF%201066(div1+2)/Meximum_Array_2.cpp)—`d1[l]++ d1[r+1]--` |
| 二维前缀和 | ✅ | [study/11.5](./study/11.5(二维前缀和差分,%20链表,%20图的存储,%20并查集,%20堆)) |
| 二维差分 | ✅ | 同上专题 |
| 高维前缀和 (SOS DP) | 无 | — |
| 前缀和 + 哈希优化 | 无 | — |

</details>

<details open>
<summary>二分法</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 二分查找 | ✅ | 各文件 |
| 二分答案 | ✅ | [D_Jumping_Through_Segments](./competition/20251120ECUT计协第六次训练赛/D_Jumping_Through_Segments.cpp) — check(mid) 维护可达区间 |
| 二分 + 差分 | ✅ | [C_租借教室](./competition/20251123ECUT计协第七次训练赛/C_租借教室.cpp) |
| 二分 + 贪心 | ✅ | [D_劫富济贫](./competition/20251123ECUT计协第七次训练赛/D_劫富济贫.cpp) |
| 实数二分 | 无 | — |
| 三分（求单峰函数极值） | 无 | — |

</details>

<details open>
<summary>双指针</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 同向双指针（滑窗） | ✅ | [d.cpp](./competition/20251110ECUT计协第四次训练赛/d.cpp) — sum 超限时收缩左指针 |
| 相向双指针 | 无 | 两数之和等 |
| 滑动窗口（定长） | ✅ | [P_1886](./study/P_1886_滑动窗口_模板_单调队列.cpp) — 单调队列 O(n) |
| 双指针 + 计数 | ✅ | [J_Range_Replace](./competition/20251214ECUT10/J_Range_Replace.cpp) |

</details>

<details open>
<summary>排序</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| sort / stable_sort | ✅ | 频繁使用 |
| 自定义排序（cmp / lambda） | ✅ | [CF_1037_D](./study/CF_1037_D_Valid_BFS.cpp) |
| nth_element / partial_sort | 无 | — |
| 归并排序（求逆序对） | 无 | — |
| 桶排序 / 基数排序 | 无 | — |

</details>

---

### 三、搜索

<details open>
<summary>DFS / BFS / 回溯 / 剪枝</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| DFS（深度优先搜索） | ✅ | [MC0456(DFS)斩断灵根](./收藏模板题/MC0456(DFS)斩断灵根.cpp) |
| BFS（广度优先搜索） | ✅ | [C_幅優先探索](./competition/20251130ECUT12/C_幅優先探索.cpp) — 网格 BFS 模板 |
| BFS 序验证 | ✅ | [CF_1037_D_Valid_BFS](./study/CF_1037_D_Valid_BFS.cpp) |
| DFS 序 | ✅ | [P_9872_DFS_Order](./study/P_9872_DFS_Order.cpp) |
| 回溯 | ✅ | [MC0509 快刀乱麻定局](./收藏模板题/MC0509%20快刀乱麻定局.cpp) |
| 记忆化搜索 | 无 | — |
| 双向 BFS | 无 | — |
| 折半搜索 (Meet in the Middle) | 无 | — |
| 剪枝技巧 | 无 | — |
| 迭代加深 (IDDFS) | 无 | — |
| A* / IDA* | 无 | — |

</details>

---

### 四、数据结构

<details open>
<summary>栈 / 队列 / 堆</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 栈 | ✅ | 多文件使用 |
| 单调栈 | ✅ | [P_5788](./study/P_5788_模板_单调栈.cpp) — NGE 模板 |
| 队列 | ✅ | BFS 等 |
| 单调队列 | ✅ | [P_1886](./study/P_1886_滑动窗口_模板_单调队列.cpp) — deque 存下标 |
| 优先队列（堆） | ✅ | [stl-hunzhan](./competition/stl-hunzhan) |
| 对顶堆（动态中位数） | 无 | — |

</details>

<details open>
<summary>并查集 (DSU)</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 路径压缩 | ✅ | [F_Cow_and_Snacks](./competition/20251130ECUT12/F_Cow_and_Snacks.cpp) — `f[x]==x? x:f[x]=find(f[x])` |
| 按秩合并 | 无 | — |
| 扩展域并查集 | ✅ | [K_团伙](./competition/20251207ECUT9/K_团伙.cpp) — 敌人关系 `merge(x+n,y)` |
| 带权并查集 | 无 | — |
| 可撤销并查集 | 无 | — |

</details>

<details open>
<summary>树状数组 (Fenwick / BIT)</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 单点修改 + 区间查询 | 无 | — |
| 区间修改 + 单点查询 | 无 | — |
| 区间修改 + 区间查询 | 无 | — |
| 求逆序对（离散化 + BIT） | 无 | — |
| 二维树状数组 | 无 | — |

</details>

<details open>
<summary>线段树</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 基础线段树（单点修改） | 无 | — |
| 区间加法 / 区间求和 (Lazy) | 无 | — |
| 区间合并 | 无 | — |
| 动态开点线段树 | 无 | — |
| 权值线段树 | 无 | — |
| 线段树 + 二分 | 无 | — |
| 吉如一线段树 (Segment Tree Beats) | 无 | — |
| 可持久化线段树（主席树） | 无 | — |

</details>

<details open>
<summary>ST 表 (Sparse Table)</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| RMQ（区间最值查询） | 无 | — |
| 静态区间 GCD | 无 | — |

</details>

<details open>
<summary>高级数据结构</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 哈希表 (unordered_set/map) | ✅ | [MC0438 姓名分数](./competition/2026matiji/MC0438%20姓名分数.cpp) |
| 字符串哈希 | 无 | — |
| Trie 字典树 | 无 | — |
| 珂朵莉树 (ODT) | 无 | — |
| 分块 (Sqrt Decomposition) | 无 | — |
| 莫队 (Mo's Algorithm) | 无 | — |
| 树套树 | 无 | — |
| Treap / FHQ-Treap | 无 | — |
| 左偏树（可并堆） | 无 | — |
| KD-Tree | 无 | — |

</details>

---

### 五、图论

<details open>
<summary>图论基础</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 邻接矩阵/邻接表存图 | ✅ | [study/11.5](./study/11.5(二维前缀和差分,%20链表,%20图的存储,%20并查集,%20堆)) |
| 图的遍历 DFS/BFS | ✅ | [C_Minimum_Steiner_Tree](./competition/20251130ECUT11/C_Minimum_Steiner_Tree.cpp) |
| 拓扑排序（ Kahn / DFS） | ✅ | 各比赛 |
| 欧拉路径 / 欧拉回路 | 无 | — |
| 哈密顿路径 | 无 | — |
| 二分图判定（染色法） | 无 | — |

</details>

<details open>
<summary>最短路</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| BFS 最短路（无权图） | ✅ | [C_幅優先探索](./competition/20251130ECUT12/C_幅優先探索.cpp) — 网格 BFS |
| 01-BFS | 无 | B_Toggle_Maze 疑似涉及 |
| Dijkstra（堆优化） | 无 | — |
| Bellman-Ford / SPFA | 无 | — |
| Floyd-Warshall | 无 | — |
| 分层图最短路 | 无 | — |
| 次短路 / K 短路 | 无 | — |

</details>

<details open>
<summary>最小生成树 (MST)</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| Kruskal | 无 | — |
| Prim（朴素 / 堆优化） | 无 | — |
| 次小生成树 | 无 | — |
| 最小瓶颈生成树 | 无 | — |

</details>

<details open>
<summary>树上问题</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 树的直径（两次 DFS / DP） | 无 | — |
| 树的重心 | 无 | — |
| 最近公共祖先 (LCA) | 无 | 倍增法 / 树剖 |
| 树上差分 | 无 | — |
| 树链剖分 (HLD) | 无 | — |
| 动态树 (LCT) | 无 | — |
| 虚树 | 无 | — |
| 点分治 | 无 | — |
| DSU on Tree (树上启发式合并) | 无 | — |
| 树上莫队 | 无 | — |

</details>

<details open>
<summary>连通性与高级图论</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 强连通分量 (Tarjan / Kosaraju) | 无 | — |
| 割点 / 割边 (桥) | 无 | — |
| 边双连通分量 (e-DCC) | 无 | — |
| 点双连通分量 (v-DCC) | 无 | — |
| 缩点 (SCC 缩点成 DAG) | 无 | — |
| 2-SAT | 无 | — |
| 差分约束 | 无 | — |
| 竞赛图 | 无 | — |
| 弦图 | 无 | — |

</details>

<details open>
<summary>网络流 / 二分图匹配</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 最大流 (Dinic / EK / ISAP) | 无 | — |
| 最小割 | 无 | — |
| 费用流 (MCMF / ZKW) | 无 | — |
| 上下界网络流 | 无 | — |
| 二分图最大匹配 (匈牙利) | 无 | — |
| 二分图最大权匹配 (KM) | 无 | — |
| 霍尔定理 (Hall's Theorem) | 无 | — |

</details>

---

### 六、动态规划

<details open>
<summary>线性 DP</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 基础线性 DP | ✅ | 各比赛中级题目 |
| 最大子段和 | 无 | — |
| 最长上升子序列 (LIS) | 无 | O(n²) / O(n log n) |
| 最长公共子序列 (LCS) | 无 | — |
| 最长回文子序列 (LPS) | 无 | — |
| 编辑距离 | 无 | — |

</details>

<details open>
<summary>背包 DP</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 01 背包 | ✅ | ECUT 训练赛题目 |
| 完全背包 | 无 | — |
| 多重背包（二进制优化） | 无 | — |
| 分组背包 | 无 | — |
| 依赖背包（树上背包） | 无 | — |
| 背包方案数 / 方案输出 | 无 | — |

</details>

<details open>
<summary>区间 DP</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 基础区间 DP（合并石子等） | 无 | — |
| 环形区间 DP | 无 | — |
| 区间 DP + 四边形不等式优化 | 无 | — |

</details>

<details open>
<summary>树形 DP</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 树上简单 DP（子树 DP） | ✅ | [C_Minimum_Steiner_Tree](./competition/20251130ECUT11/C_Minimum_Steiner_Tree.cpp) 涉及 |
| 树形背包 (树上分组背包) | 无 | — |
| 换根 DP (reroot DP) | 无 | — |
| 基环树 DP | 无 | — |

</details>

<details open>
<summary>状压 DP (Bitmask DP)</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 基础状压 DP | 无 | — |
| 旅行商问题 (TSP) | 无 | — |
| 子集枚举优化 | 无 | — |
| 插头 DP (轮廓线 DP) | 无 | — |

</details>

<details open>
<summary>数位 DP (Digit DP)</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 基础数位 DP | 无 | — |
| 数位 DP + 二分 | 无 | — |

</details>

<details open>
<summary>DP 优化</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 滚动数组 | 无 | — |
| 前缀和优化 DP | 无 | — |
| 单调队列优化 DP | 无 | — |
| 斜率优化 (Convex Hull Trick) | 无 | — |
| 四边形不等式优化 | 无 | — |
| 矩阵快速幂优化 DP | 无 | — |
| 数据结构优化 DP（线段树/BIT） | 无 | — |

</details>

<details open>
<summary>概率 / 期望 DP</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 概率 DP | 无 | — |
| 期望 DP | 无 | — |
| 马尔可夫链 / 高斯消元解期望 | 无 | — |

</details>

<details open>
<summary>其他 DP</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 博弈 DP | 无 | — |
| DAG 上 DP | 无 | — |
| 后缀自动机 DP | 无 | — |
| DP 套 DP | 无 | — |

</details>

---

### 七、数学

<details open>
<summary>数论基础</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| GCD / LCM / 欧几里得 | ✅ | [main.cpp](./main.cpp) — lcm(12,18) |
| 质因数分解（试除） | ✅ | [c.cpp](./competition/2025ECPC/c.cpp) — O(√n) 模板 |
| 埃氏筛 / 线性筛 | 无 | — |
| 欧拉函数 (φ) | 无 | — |
| 扩展欧几里得 (Exgcd) | 无 | 解同余方程 |
| 乘法逆元 (费马 / Exgcd / 线性) | 无 | — |
| 中国剩余定理 (CRT / ExCRT) | 无 | — |
| 离散对数 (BSGS) | 无 | — |
| 莫比乌斯反演 | 无 | — |
| 杜教筛 / Min_25 筛 | 无 | — |
| 原根 / 阶 | 无 | — |
| 二次剩余 | 无 | — |

</details>

<details open>
<summary>组合数学</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 排列组合基础 | ✅ | [Card_Game](./competition/2026.2.3NEWK1/Card_Game.cpp) — MOD 阶乘计数 |
| 杨辉三角 / 组合数递推 | 无 | — |
| 卢卡斯定理 (Lucas) | 无 | — |
| 卡特兰数 (Catalan) | 无 | — |
| 斯特林数 (Stirling) | 无 | — |
| 容斥原理 | 无 | — |
| 多项式 / 生成函数 | 无 | — |
| Burnside 引理 / Polya 计数 | 无 | — |

</details>

<details open>
<summary>博弈论</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 巴什博弈 | 无 | — |
| Nim 游戏 / SG 函数 | 无 | — |
| 威佐夫博弈 | 无 | — |
| 不平等博弈 | 无 | — |

</details>

<details open>
<summary>线性代数</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 矩阵运算 / 快速幂 | 无 | — |
| 高斯消元 | 无 | — |
| 线性基 | 无 | — |
| 矩阵树定理 | 无 | — |

</details>

<details open>
<summary>多项式</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| FFT（快速傅里叶变换） | 无 | — |
| NTT（快速数论变换） | 无 | — |
| 多项式求逆 / ln / exp / 开根 | 无 | — |
| 拉格朗日插值 | 无 | — |

</details>

<details open>
<summary>其他数学</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 快速幂（模意义） | 无 | — |
| 矩阵快速幂 | 无 | — |
| 整数分块（数论分块） | 无 | — |
| 离散化 | 无 | — |
| 随机化算法（模拟退火等） | 无 | — |

</details>

---

### 八、字符串

<details open>
<summary>字符串算法</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 字符串基本操作 | ✅ | 多文件 |
| 字符串哈希 (Rolling Hash) | 无 | — |
| KMP（前缀函数） | 无 | — |
| Z 函数（Z-algorithm） | 无 | — |
| Manacher（回文串） | 无 | — |
| 最小表示法 | 无 | — |
| 后缀数组 (SA) | 无 | — |
| 后缀自动机 (SAM) | 无 | — |
| 后缀树 | 无 | — |
| AC 自动机（多模式串匹配） | 无 | — |
| 回文自动机 (PAM) | 无 | — |
| 表达式求值 | 无 | — |

</details>

---

### 九、计算几何

<details open>
<summary>计算几何</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 向量基础（点积 / 叉积） | 无 | — |
| 线段相交判定 | 无 | — |
| 多边形面积（鞋带公式） | 无 | — |
| 凸包（Andrew / Graham） | 无 | — |
| 旋转卡壳（最远点对） | 无 | — |
| 半平面交 | 无 | — |
| 最近点对（分治） | 无 | — |
| 三角剖分 / Delaunay | 无 | — |
| 圆相关（相交、面积并） | 无 | — |

</details>

---

### 十、进阶与杂项

<details open>
<summary>离线算法 / 分治</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 普通莫队 | 无 | — |
| 带修莫队 | 无 | — |
| 回滚莫队 | 无 | — |
| CDQ 分治 | 无 | — |
| 整体二分 | 无 | — |
| 分治 FFT | 无 | — |

</details>

<details open>
<summary>经典问题模型</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| 最大子段和 (Kadane) | 无 | — |
| 最大子矩阵 (悬线法) | 无 | — |
| 括号序列 / 表达式解析 | 无 | — |
| 约瑟夫问题 | 无 | — |
| 任务调度 / 流水线 | 无 | — |
| 曼哈顿距离转切比雪夫 | 无 | — |

</details>

<details open>
<summary>输入输出优化与调试</summary>

| 知识点 | 状态 | 位置/备注 |
|-------|------|----------|
| `ios::sync_with_stdio(false)` + `cin.tie(nullptr)` | ✅ | 每个文件 |
| `freopen` 文件重定向 | ✅ | 注释在代码中 |
| 快读 (`getchar` / `cin.read`) | 无 | — |
| `#define int long long` + `signed main()` | ✅ | 大量使用 |
| `endl` vs `'\n'` | ✅ | 统一用 `'\n'` |
| `const int INF = 0x7f7f7f7f` | ✅ | 部分文件 |

</details>

---

## 📁 目录概览

| 目录 | 说明 |
|------|------|
| [study/](./study) | **日常学习** — 按日期/主题组织的练习题，含洛谷、CF、AtCoder 等 |
| [competition/](./competition) | **比赛训练** — ECUT 计协训练赛、ECPC 省赛、NewCode、牛客周赛等 |
| [tiantisai/](./tiantisai) | **天梯赛专题** — 含个人解法与 std 标准参考 |
| [收藏模板题/](./收藏模板题) | **经典模板** — 并查集、DFS、BFS 等收藏题目 |

---

## 🏆 训练记录

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
| 2025.11 | Pinely Round 5 | [study/Pinely Round 5 (Div. 1 + Div. 2)](./study/Pinely%20Round%205%20(Div.%201%20+%20Div.%202)) |
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
| 2026.03 | 天梯赛 | [tiantisai](./tiantisai) |
| — | AtCoder ABC | [competition/ATC436](./competition/ATC436) |
| — | CF Round 1090 (Div. 4) | [study/Codeforces Round 1090 (Div. 4)](./study/Codeforces%20Round%201090%20(Div.%204)) |
| — | 牛客周赛 | [competition/牛客周赛 Round 114](./competition/牛客周赛%20Round%20114) |
| — | 传智杯 | [competition/传智杯](./competition/传智杯) |

### STL 专题

| 专题 | 链接 |
|------|------|
| STL 综合应用 | [competition/stl-hunzhan](./competition/stl-hunzhan) |

---

## 📌 模板收藏

| 题目 | 算法 | 位置 |
|------|------|------|
| F_Cow_and_Snacks | DSU 并查集判环 + 路径压缩 | [收藏模板题](./收藏模板题/F_Cow_and_Snacks.cpp) |
| K_团伙 | 扩展域并查集（敌人关系） | [competition/20251207ECUT9](./competition/20251207ECUT9/K_团伙.cpp) |
| Valid BFS | BFS 序验证 | [收藏模板题](./收藏模板题/Valid%20BFS.cpp) |
| MC0456(DFS)斩断灵根 | DFS 搜索 | [收藏模板题](./收藏模板题/MC0456(DFS)斩断灵根.cpp) |
| MC0509 快刀乱麻定局 | 回溯搜索 | [收藏模板题](./收藏模板题/MC0509%20快刀乱麻定局.cpp) |
| P_1886 滑动窗口 | 单调队列（deque） | [study/](./study/P_1886_滑动窗口_模板_单调队列.cpp) |
| P_5788 单调栈 | 单调栈 NGE | [study/](./study/P_5788_模板_单调栈.cpp) |
| P_9872 DFS Order | DFS 序 + 子树大小 | [study/](./study/P_9872_DFS_Order.cpp) |
| C_幅優先探索 | BFS 网格搜索 | [competition/20251130ECUT12](./competition/20251130ECUT12/C_幅優先探索.cpp) |
| C_Minimum_Steiner_Tree | 树上 DFS + 剪枝 | [competition/20251130ECUT11](./competition/20251130ECUT11/C_Minimum_Steiner_Tree.cpp) |

---

## ⚡ 你代码里的套路总结

从你所有代码中提炼出的常用写法：

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
merge(x + n, y);  // x 的敌人和 y 是同类
merge(y + n, x);  // y 的敌人和 x 是同类
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

### 9. BFS 网格 (双队列存坐标)

```cpp
queue<int> qx, qy;
qx.push(sx); qy.push(sy);
while(qx.size()) {
    for(int i = 0; i < 4; i++) {
        int x = qx.front() + dx[i];
        int y = qy.front() + dy[i];
        if(合法) {
            qx.push(x); qy.push(y);
            dist[x][y] = dist[qx.front()][qy.front()] + 1;
        }
    }
    qx.pop(); qy.pop();
}
```

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
