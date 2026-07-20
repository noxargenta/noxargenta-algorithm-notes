#include <iostream>
#include <vector>

using namespace std;

void solve_meow() {
    int n, m, k;
    if (!(cin >> n >> m >> k)) return;
    
    // 特判 k = 0
    if (k == 0) {
        // 只有 1 维地图允许填全 0（因为不存在 2x2 的区域）
        if (n == 1 || m == 1) {
            cout << "Yes\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) cout << 0;
                cout << "\n";
            }
        } else {
            cout << "No\n"; // 二维矩阵全 0 必然违反 "2x2区域必含1" 规则
        }
        return;
    }
    
    // 最大连通块数（国际象棋黑白染色上限）
    int max_k = (n * m + 1) / 2;
    if (k > max_k) {
        cout << "No\n";
        return;
    }
    
    vector<vector<int>> grid(n, vector<int>(m, 0));
    
    // 1. 铺设独立骨架：在所有的 (偶数行, 偶数列) 放置积木
    int mid = 0;
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
            grid[i][j] = 1;
            mid++;
        }
    }
    
    // 2. 根据所需的 k 做加减法
    if (k < mid) {
        // 需要合并连通块：每加 1 条边（桥梁），连通块数量精确 -1
        int need_edges = mid - k;
        
        // 【横向加桥】：将同一行相邻的孤立块连起来
        for (int i = 0; i < n; i += 2) {
            // 注意条件 j + 1 < m，确保桥的右侧一定有我们要连的 1
            for (int j = 1; j + 1 < m; j += 2) {
                if (need_edges > 0) {
                    grid[i][j] = 1;
                    need_edges--;
                }
            }
        }
        
        // 【纵向加桥】：如果在横向连成条纹后还要减少连通块，就在最左边一列纵向往下连（画 E 的竖线）
        // 同样注意 i + 1 < n 确保下面有目标行
        for (int i = 1; i + 1 < n; i += 2) {
            if (need_edges > 0) {
                grid[i][0] = 1;
                need_edges--;
            }
        }
        
    } else if (k > mid) {
        // 需要增加孤立点：在保证不与骨架相连的安全区（奇数行, 奇数列）投放新的连通块
        int need_nodes = k - mid;
        
        for (int i = 1; i < n; i += 2) {
            for (int j = 1; j < m; j += 2) {
                if (need_nodes > 0) {
                    grid[i][j] = 1;
                    need_nodes--;
                }
            }
        }
    }
    
    // 3. 输出结果
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

int main() {
    // 优化 I/O 读取速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve_meow();
    return 0;
}