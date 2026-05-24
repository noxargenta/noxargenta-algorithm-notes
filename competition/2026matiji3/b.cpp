#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    vector<string> a(n+1);
    vector<int> cnt(n+1,0);
    vector<string> b(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
        for(int j=1;j<=n;j++){
            int ok=1;
            if(b[i].length()>a[i].length()){
                continue;
            }
            for(int k=0;k<b[i].length();k++){
                if(a[j][k]!=b[i][k]){
                    ok=0;
                    break;
                }
            }
            if(ok){
                cnt[j]++;
            }else {
                continue;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << cnt[i] << ' ';
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