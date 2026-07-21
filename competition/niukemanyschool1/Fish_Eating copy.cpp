//     /ᐠ˶˶ᐟ\
//   (=•ㅅ < )
//  |￣∪∪￣|
//  |＿求AC＿|

#include <bits/stdc++.h>
using namespace std;

// 使用 long long 防止体型计算和坐标解密时溢出
using ll = long long;
using vi = vector<int>;

const int N = 250005;

// --- 全局并查集数据结构 ---
int fa[N];   // fa[x] 存储节点 x 的父节点。在这里，父子关系代表了“被吞并”的关系。
int sz[N];   // sz[x] 存储以 x 为根的连通块中鱼的总数量。
ll mx[N];    // mx[x] 核心变量：存储节点 x 跨越到其父节点所需的“最小初始体型门槛”。
             // 在路径压缩后，mx[x] 会变成从 x 出发到达当前整个大连通块根节点所需的“最高门槛”。

// 方向数组：用于处理格子的上下左右邻居
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

/**
 * 查找根节点并进行路径压缩
 * 在压缩的过程中，利用带权并查集的思想，更新当前节点到根节点的“最高门槛”。
 */
int find(int x) {
    if (fa[x] != x) {
        int pre = fa[x];       // 记录当前的直属父亲
        int rt = find(fa[x]);  // 递归找到终极祖宗（即当前连通块中最新、最大的那条鱼）
        
        // 路径压缩：直接指向祖宗
        fa[x] = rt;
        
        // 更新门槛：x 要想吃到祖宗那个级别，必须既能吃掉原来的父亲，也能跨越父亲到祖宗之间的所有门槛。
        // 所以取最大值。
        mx[x] = max(mx[x], mx[pre]);
    }
    return fa[x];
}

/**
 * 合并函数：将旧鱼所在的连通块 (b) 合并到新放置的大鱼 (a) 所在的连通块下。
 * @param a 新鱼所在的根
 * @param b 旧鱼所在的根
 * @param val 新鱼的大小
 */
int merge(int a, int b, ll val) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return ra;

    // 计算门槛：旧连通块 rb 里的鱼要想吃掉新加入的大小为 val 的大鱼，
    // 它必须先吃光 rb 内部所有的鱼（共 sz[rb] 条）。
    // 假设初始大小为 S，吃完后大小为 S + sz[rb] - 1。
    // 必须满足 S + sz[rb] - 1 >= val  =>  S >= val - sz[rb] + 1。
    // 这个 val - sz[rb] + 1 就是 rb 跨向新世界的“入门门槛”。
    mx[rb] = max(mx[rb], val - 1ll * sz[rb] + 1);

    // 更新新根 ra 的总鱼数：新鱼吃掉了旧连通块所有的鱼
    sz[ra] += sz[rb];
    
    // 建立父子关系：新来的大鱼作为父节点
    fa[rb] = ra;
    return ra;
}

int main() {
    // 优化输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    int sum = n * m;

    // 初始化并查集
    for (int i = 1; i <= sum; i++) {
        fa[i] = i;
        sz[i] = 1; // 初始每个格子如果放鱼，数量为 1
        mx[i] = 0; // 初始没有门槛
    }

    // siz[id] 存储编号为 id 的鱼被放置时的原始大小 v，-1 表示当前是障碍物
    vi siz(sum + 5, -1);
    ll last = 0; // 存储上一次操作的答案，用于解密 XOR 坐标

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            // --- 操作 1：放置新鱼 ---
            int xp, yp; ll v;
            cin >> xp >> yp >> v;
            int x = xp ^ (int)last; // XOR 解密坐标
            int y = yp ^ (int)last;
            int id = (x - 1) * m + y; // 二维转一维索引
            
            siz[id] = v; // 放置鱼
            
            // 检查四个相邻方向
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                
                int nid = (nx - 1) * m + ny;
                // 如果邻居有鱼，则进行合并
                if (siz[nid] != -1) {
                    int r_current = find(id);
                    int r_neighbor = find(nid);
                    if (r_current != r_neighbor) {
                        // 题目保证新放的鱼 v 一定是当前最大的，所以新鱼所在的根始终作为 merge 的第一个参数
                        merge(r_current, r_neighbor, v);
                    }
                }
            }
            
            // 结果：当前连通块内鱼的总数 - 1（不含自己）
            int rt = find(id);
            last = sz[rt] - 1;
            cout << last << '\n';
        } 
        else {
            // --- 操作 2：查询旧鱼通关所需的最小增加量 ---
            int xp, yp;
            cin >> xp >> yp;
            int x = xp ^ (int)last;
            int y = yp ^ (int)last;
            int id = (x - 1) * m + y;
            
            ll v0 = siz[id]; // 这条鱼最初的大小
            
            // 触发一次 find，路径压缩会同时计算出 mx[id]
            // mx[id] 现在是从该鱼出发，吃遍当前整个连通块所需的最小初始体型
            find(id);
            ll need = mx[id];
            
            // 答案 = 目标体型 - 初始体型。如果原本就够大，则为 0。
            last = max(0LL, need - v0);
            cout << last << '\n';
        }
    }

    return 0;
}