#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int mex = 0; // 期待出现的下一个最小非负整数
    for(int x : a) {
        if(x == mex) {
            mex++; // 找到了期待的数，期待下一个
        } else if(x > mex) {
            // 发现当前的数跳过了期待的 mex，说明 mex 就是我们要找的
            break;
        }
        // 如果 x < mex，说明是重复元素，直接跳过
    }
    cout << mex << endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}