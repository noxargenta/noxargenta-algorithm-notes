#include <iostream>
#include <vector>
#include "Lazy_Shuffling.h"

using namespace std;

const int MOD = 998244353;
// dp数组开到 2^22，用来存各种“修课状态”下的方案数
// 因为数组很大（约16MB），必须开在全局区，不能开在 main 函数里面防止爆栈
int dp[1 << 22]; 
// req[i] 用来记录节点 i 的“前置课”集合（用二进制压缩表示）
int req[25]; 

int main() {
    // 基础优化：加快 cin 和 cout 的读取速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> p(n);
    vector<int> pinv(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--; // 强烈建议！转为从 0 开始计数，为了后面和二进制位完美对应
        pinv[p[i]] = i; // 记录原来在位置 p[i] 的元素，新位置变成了 i
    }

    int k = 0;
    // 双重循环找“反转对”，构建先决条件图
    for (int u = 0; u < n; ++u) {
        for (int v = u + 1; v < n; ++v) {
            // 如果原本 u 在 v 左边，打乱后 u 跑到了 v 右边，这就是反转对
            if (pinv[u] > pinv[v]) {
                // v 的前置课里加上 u。(1 << u) 就是把二进制第 u 位置为 1
                req[v] |= (1 << u); 
                k++;
            }
        }
    }

    // 极端边界情况：如果没有反转对 (k=0)
    // 说明不管怎么排，差值永远是0（这就是最大值了）
    // 那所有的 n! 种排列都是合法的。
    if (k == 0) {
        long long ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans = (ans * i) % MOD;
        }
        cout << ans << "\n";
        return 0;
    }

    // 初始状态：一门课都没上的方案数是 1
    dp[0] = 1; 
    
    // 外层循环：遍历所有的修课状态 mask (从 1 到 2^n - 1)
    for (int mask = 1; mask < (1 << n); mask++) {
        
        long long sum = 0; // 用来存当前状态 mask 有多少种修法
        
        // 内层循环：我们把 n 门课全部看一遍，试试能不能挑出一门作为“最后上的课”
        for (int i = 0; i < n; i++) {
            
            // 判断 1：当前状态 mask 里面，到底有没有选课程 i ？
            // (mask & (1 << i)) 如果不为 0，说明 mask 里包含课程 i
            if (mask & (1 << i)) {
                
                // 如果包含，那么在修课程 i 之前的状态叫 pre（把 i 从 mask 里划掉）
                // ^ (1 << i) 的作用就是把第 i 位变成 0
                int pre = mask ^ (1 << i);
                
                // 判断 2：在状态 pre 时，课程 i 所有的前置课 (req[i]) 都上完了吗？
                // (req[i] & pre) == req[i] 的意思就是 req[i] 需要的课，pre 里全都有
                if ((req[i] & pre) == req[i]) {
                    // 如果满足，说明可以通过状态 pre，再上个课程 i，变成当前状态 mask
                    sum = (sum + dp[pre]) % MOD; 
                }
            }
        }
        
        // 把累加好的方案数存进 dp 数组
        dp[mask] = sum; 
    }

    // 完整的拓扑排序数量就是所有课都上完的状态：dp[(1 << n) - 1]
    // 最终答案 = 拓扑排序数 * 2 (别忘了题目有两种极端情况)
    long long ans = (2LL * dp[(1 << n) - 1]) % MOD;
    cout << ans << "\n";
}