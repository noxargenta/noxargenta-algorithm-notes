#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int S = 0;
    
    // 读取输入并计算总异或和 S
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        S ^= a[i];
    }

    // 掩码：将 S 中为 1 的位清零，保留 S 中为 0 的位
    int mask = ~S;
    vector<int> basis(30, 0);

    // 将变换后的元素插入线性基
    for (int i = 0; i < n; ++i) {
        int x = a[i] & mask;
        for (int j = 29; j >= 0; --j) {
            if ((x >> j) & 1) {
                if (!basis[j]) {
                    basis[j] = x;
                    break;
                }
                x ^= basis[j];
            }
        }
    }

    // 求在该线性基下能异或出的最大值 M
    long long M = 0;
    for (int j = 29; j >= 0; --j) {
        if ((M ^ basis[j]) > M) {
            M ^= basis[j];
        }
    }

    // 最终得分为 S + 2 * M
    long long ans = S + 2LL * M;
    cout << ans << "\n";
}

int main() {
    // 优化标准 I/O 操作速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}