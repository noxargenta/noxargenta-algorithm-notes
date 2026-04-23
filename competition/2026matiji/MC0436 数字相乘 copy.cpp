#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >>n;
    int val=1;
    int cnt2 = 0, cnt5 = 0;
    for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    // 除去因子 2
    while (x > 0 && x % 2 == 0) { cnt2++; x /= 2; }
    // 除去因子 5
    while (x > 0 && x % 5 == 0) { cnt5++; x /= 5; }
    // 剩下的部分乘到 val 里，只保留个位
    val = (val * (x % 10)) % 10;
    }

    // 把多出的因子 2 乘回来（因为 2 的数量一般多于 5）
    for (int i = 0; i < cnt2 - cnt5; i++) {
        val = (val * 2) % 10;
    }
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}