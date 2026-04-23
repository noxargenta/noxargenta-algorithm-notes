#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    map<int,int> x;
    vector<vector<int>> a(m,vector<int> (n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    int res=0;
    int te=0;
    for(int i=0;i<m;i++){
        te=0;
        for(int j=0;j<n;j++){
            if(a[i][j]==k){
                te++;
                if(te>=(n+1)/2){
                    res++;
                    break;
                    te=0;
                }
            }else {
                continue;
            }
        }
    }
    if(res>=(m+1)/2){
        cout << "YES\n";  
    }else{
        cout << "NO\n";
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