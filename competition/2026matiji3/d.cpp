#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    a[0]=-1;
    for(int i=1;i<=q;i++){
        int l,r;
        cin >> l >>r;
        int sum=1;
        int las=l;
        //int ok=0;
        int maxx=0;
        for(int j=l;j<=r;j++){
            if(j==las)continue;
            if(a[j]>a[i-1]){
                sum++;
            }else {
                las=j;
                sum=1;
            }
            cout << sum << endl;
            maxx=max(maxx,sum);
        }
        if(maxx>=3){
            cout << "Yes\n";
        }else {
            cout << "No\n";
        }
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