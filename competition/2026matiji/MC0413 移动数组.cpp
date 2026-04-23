#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,q;
    cin >> n >> q;
    deque<int> a;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        if(x==1){
            a.push_back(a.front());
            a.pop_front();
        }else {
            a.push_front(a.back());
            a.pop_back();
        }
    }
    for(int i=1;i<=n;i++){
        int x=a.front();
        cout << x << " ";
        a.pop_front();
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