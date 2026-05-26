#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int b[200],vis[200];
bool isPrime(int x){
    if(x<2){
        return 0;
    }else {
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                return 0;
            }
        }
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    auto dfs = [&](int u,int fa) -> int{
        
    };
    int cnt=dfs(1,0);
    cout << cnt << endl;
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