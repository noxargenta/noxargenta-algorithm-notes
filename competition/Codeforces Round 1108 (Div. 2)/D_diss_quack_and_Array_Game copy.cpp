#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // f(x): 单独把数字 x 变成 0 需要的步数 (二进制1的个数 + 二进制长度 - 1)
    auto f = [&](i64 x) -> i64 {
        
    };

    i64 ans = 2e18;
    
    // 暴力枚举全场都变成 2^v 的倍数
    for(i64 v = 0; v <= 17; v++) {
        i64 cur = 0, step = 1LL << v;
        
        for(int i = 0; i < n; i++) {
            i64 mn = 2e18;
            // 找到 >= a[i] 且最近的 step 的倍数
            i64 x = ((a[i] + step - 1) / step) * step;
            if(!x) x = step;
            
            // 往后稍微搜一点点，因为多加几次 1 可能会让二进制 1 的个数骤减
            for(i64 nxt = x; nxt - x <= 60; nxt += step) {
                mn = min(mn, nxt - a[i] + f(nxt));
            }
            cur += mn;
        }
        
        // 每次全体被除以 2，能省去 n-1 步 (因为一刀劈了 n 个怪，相当于赚了 n-1 次单体攻击)
        cur -= (n - 1) * v;
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int _; cin >> _;
    while(_--) solve();
    return 0;
}