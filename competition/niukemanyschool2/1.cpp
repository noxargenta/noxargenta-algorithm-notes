#include <iostream>

using namespace std;

const int MOD = 998244353;
// dp[S] 表示剩余未确定拓扑序的集合为 S 时的方案数
long long dp[1 << 22]; 
// in_edge[u] 存储指向节点 u 的所有节点的集合（入边集合）
int in_edge[25]; 
int p[25];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--; // 转为从 0 开始计数，使其符合位运算索引 [0, n-1]
    }

    int inv_count = 0; // 记录 p 数组中的逆序对数量

    // 严谨对应题解：对于 p 中所有的逆序对 (i, j)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // 如果满足 i < j 且 p_i > p_j
            if (p[i] > p[j]) {
                // 设 u = p_i, v = p_j，建立从小的数指向大的数的有向图 u -> v
                int u = p[i];
                int v = p[j];
                // 节点 u 指向了节点 v，因此 u 属于 v 的入边集合
                in_edge[v] |= (1 << u); 
                inv_count++;
            }
        }
    }

    // 对应题解最后一段：没有逆序对时，直接输出 n!
    if (inv_count == 0) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = (ans * i) % MOD;
        }
        cout << ans << "\n";
        return 0;
    }

    // DP 初始化：当剩余集合为空时，拓扑排序完成，这计为 1 种有效方案
    dp[0] = 1;

    // 对应题解第三段：枚举所有尚未确定拓扑序的子集 S (从 1 到 2^n - 1)
    for (int S = 1; S < (1 << n); S++) {
        long long sum = 0;

        // 枚举集合 S 中的每一个点 u，尝试将其取出
        for (int u = 0; u < n; u++) {
            
            // 判定 1：点 u 必须存在于当前子集 S 中
            if (S & (1 << u)) {
                
                // 判定 2：将其(u的入边情况)和 S 进行与运算看结果是否为 0
                // 含义：子集 S 中，没有任何一个节点有边指向 u
                if ((in_edge[u] & S) == 0) {
                    
                    // 若结果为 0，则可以将 dp[S - {u}] 转移到 dp[S] 中
                    // S ^ (1 << u) 就是集合 S 去除点 u 的位运算写法
                    sum = (sum + dp[S ^ (1 << u)]) % MOD;
                }
            }
        }
        dp[S] = sum;
    }

    // 题解最后一段：两个条件对应图相反，答案 * 2
    // 最终要求的答案就是全集 S = (1 << n) - 1 时的方案数乘以 2
    long long ans = (2LL * dp[(1 << n) - 1]) % MOD;
    cout << ans << "\n";

    return 0;
}