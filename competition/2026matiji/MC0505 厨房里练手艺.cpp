#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1);
    //vector<int> b(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        //b[i]=a[i]+a[i-1];
    }
    for(int i=1;i<=q;i++){
        int opt;
        cin >> opt;
        if(opt==1){
            int l,r,x;
            cin >> l >> r >> x;
            int ii=1;
            for(int j=l;j<=r;j++){
                //a[j]+=x*ii;
                //ii++;
                a[j]+=x;
            }
        }else if(opt==2){
            int l,r,x;
            cin >> l >> r >> x;
            for(int j=l;j<=r;j++){
                if(a[j]>x){
                    a[j]=x;
                }
            }
        }else {
            int l,r;
            cin >> l >> r;
            int sum=0;
            for(int j=l;j<=r;j++){
                sum+=a[j];
            }
            cout << sum <<endl;
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