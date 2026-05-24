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
    while(q--){
        int l,r;
        cin >> l >> r;
        int ok1=0;
        int ok2=0;
        for(int i=l;i<=r;i++){
            int ll=i,rr=i;
            int okl=0;
            int okr=0;
            while(true){
                if(a[ll]<a[i]){
                    okl=1;
                }
                if(a[rr]>a[i]){
                    okr=1;
                }
                if(okl==1 && okr==1){
                    cout << "Yes\n";
                    ok2=1;
                    ok1=1;
                    break;
                }
                if(ll==l && rr==r){
                    break;
                }
                if(ll!=l){
                    ll--;
                }
                if(rr!=r){
                    rr++;
                }
            }
            if(ok2==1){
                break;
            }
        }
        if(ok1==1){
            break;
        }
        cout << "No\n";
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