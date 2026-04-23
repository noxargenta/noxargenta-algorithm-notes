#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin  >> n >> m;
    int a[n][m];
    int list[n];
    fill(list,list+n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];

        }
    }
    int q;
    cin  >> q;
    while(q--){
        int opt,y,k;
        cin >> opt >> y >> k;
        int x=y-1;
        if(opt==1)list[x]=(list[x]+k)%m;
        else{
            list[x]-=k;
            list[x]=(list[x]+m)%m;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][(list[i]+j+m)%m] << ' ';
        }
        cout << endl;
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