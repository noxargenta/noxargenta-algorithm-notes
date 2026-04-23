#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

// 因为 n 最大是 200，端点最多有 400 个。
// dp[层数][左端点][右端点]：记录某个区间内，刚好凑出某层数的方案数
int dp[205][405][405];

// pre[层数][左端点][右端点]：记录某个区间内，凑出的层数 <= 某层数的总方案数(前缀和)
int pre[205][405][405];

// e[l] 就像一个登记册，记录“所有从左端点 l 开始的线段，它们的右端点在哪里”
vector<int> e[405]; 

int main() {
    // 优化输入输出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // 存储一开始输入的线段
    vector<pair<int, int>> segments(n + 1); 
    // 用于“离散化”的篮子，把所有坐标装进去
    vector<int> ls; 

    /* ==========================================
       第一战区：读入数据与离散化 (坐标压缩)
       ========================================== */
    for (int i = 1; i <= n; i++) {
        cin >> segments[i].first >> segments[i].second;
        ls.push_back(segments[i].first);
        ls.push_back(segments[i].second);
    }

    // 将所有坐标从小到大排序，并去掉重复的坐标
    sort(ls.begin(), ls.end());
    ls.erase(unique(ls.begin(), ls.end()), ls.end());

    // sz 是压缩后一共有多少个不同的坐标点
    int sz = ls.size();

    // 将原坐标替换为 1, 2, 3... 这样的小号，并登记到 e 数组中
    for (int i = 1; i <= n; i++) {
        // lower_bound 用于查找原坐标在压缩列表中的位置
        int l_idx = lower_bound(ls.begin(), ls.end(), segments[i].first) - ls.begin() + 1;
        int r_idx = lower_bound(ls.begin(), ls.end(), segments[i].second) - ls.begin() + 1;
        e[l_idx].push_back(r_idx);
    }

    /* ==========================================
       第二战区：打底子 (初始化 0 层状态)
       ========================================== */
    // 注意边界开到 sz + 1，防止后面的 [l+1] 或 [p+1] 越界
    for (int i = 0; i <= sz + 1; i++) {
        for (int j = 0; j <= sz + 1; j++) {
            // “什么都不画”也是一种合法画法，最高层数为 0
            dp[0][i][j] = 1; 
        }
    }
    for (int k = 0; k <= n; k++) {
        for (int l = 0; l <= sz + 1; l++) {
            for (int r = 0; r <= sz + 1; r++) {
                // 既然 0 层方案数是 1，那么初始状态下“<= k层”的方案数底薪就是 1
                pre[k][l][r] = 1; 
            }
        }
    }

    /* ==========================================
       第三战区 & 第四战区：区间 DP 核心推导
       ========================================== */
    for (int k = 1; k <= n; k++) {                         // 枚举目标层数 k
        for (int len = 1; len <= sz; len++) {              // 枚举当前观察的直尺长度 len
            for (int l = 1; l + len - 1 <= sz; l++) {      // 枚举直尺的左端点 l
                int r = l + len - 1;                       // 算出直尺的右端点 r

                // 基础选择：如果不在起点 l 画任何最外层线段
                // 那么这片区域的画法，等同于去掉了最左边一点后的区域画法
                dp[k][l][r] = (dp[k][l][r] + dp[k][l + 1][r]) % MOD;

                // 复杂选择：如果选择画一条从 l 开始的线段
                // 遍历登记册，找到所有以 l 为起点的线段，p 是它的右端点
                for (int p : e[l]) {
                    // 如果这条线段太长，超出了我们当前观察的直尺范围，就不考虑
                    if (p > r) continue; 

                    if (p == r) {
                        // 特殊情况：这条线段完美覆盖了整个 [l, r] 区间
                        // 因为没有“外部区域”了，只用管“内部区域” [l+1, r-1]
                        if (k == 1) {
                            // 只要凑1层，这条线段本身就是1层，内部什么都不准画(即1种空集画法)
                            dp[k][l][r] = (dp[k][l][r] + 1) % MOD;
                        } else {
                            // 要凑k层，外面这条线段占了1层，内部必须刚好凑齐 k-1 层
                            dp[k][l][r] = (dp[k][l][r] + dp[k - 1][l + 1][r - 1]) % MOD;
                        }
                    } else {
                        // 普遍情况：大线段是 [l, p]，它把世界分成了：
                        // 内部区域：[l+1, p-1]
                        // 外部区域：[p+1, r]

                        // 套路 A：内部刚好凑 k-1 层 (用dp) × 外部随便只要不超 k 层 (用pre)
                        long long wayA = 1LL * dp[k - 1][l + 1][p - 1] * pre[k][p + 1][r] % MOD;
                        
                        // 套路 B：内部随便只要不超 k-1 层 (用pre) × 外部刚好凑 k 层 (用dp)
                        long long wayB = 1LL * pre[k - 1][l + 1][p - 1] * dp[k][p + 1][r] % MOD;
                        
                        // 去重：减去 (内部刚好 k-1 层) 且 (外部刚好 k 层) 的被重复计算的次数
                        long long overlap = 1LL * dp[k - 1][l + 1][p - 1] * dp[k][p + 1][r] % MOD;

                        // 把上述三种情况合并进去
                        dp[k][l][r] = (dp[k][l][r] + wayA) % MOD;
                        dp[k][l][r] = (dp[k][l][r] + wayB) % MOD;
                        
                        // C++中减法取模可能出现负数，加上 MOD 再取模可以修正为正数
                        dp[k][l][r] = (dp[k][l][r] - overlap + MOD) % MOD; 
                    }
                } // 结束属于 l 的线段遍历

                // 当前区间 [l, r] 在刚好 k 层的方案数算完了
                // 立刻更新辅助登记表 pre (<=k层 的方案数)
                pre[k][l][r] = (pre[k - 1][l][r] + dp[k][l][r]) % MOD;

            } // 结束枚举左端点 l
        } // 结束枚举区间长度 len
    } // 结束枚举层数 k

    /* ==========================================
       第五战区：结账算总得分
       ========================================== */
    long long ans = 0; // 记录最终答案
    for (int k = 1; k <= n; k++) {
        // dp[k][1][sz] 代表在整把完整的尺子 [1, sz] 上，最高套娃刚好为 k 层的方案数
        // 这部分方案产生的得分为：层数 k * 对应的方案数
        ans = (ans + 1LL * k * dp[k][1][sz]) % MOD;
    }

    // 打印答案
    cout << ans << "\n";

    return 0;
}