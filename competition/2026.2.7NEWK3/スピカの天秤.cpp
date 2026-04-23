#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1),b(m+1);
    int suma=0,sumb=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        suma+=a[i];
    }
    sort(a.begin()+1,a.end(),greater());
    for(int i=1;i<=m;i++){
        cin >>b[i];
        sumb+=b[i];
    }
    sort(b.begin()+1,b.end(),greater());
    if(suma==sumb){
        cout << 1 << endl;
    }else if(suma>sumb){
        for(int i=1;i<=n;i++){
            suma-=a[i];
            if(suma<=sumb){
                cout << i << endl;
                break;
            }
        }
    }else {
        for(int i=1;i<=m;i++){
            sumb-=b[i];
            if(suma>=sumb){
                cout << i << endl;
                break;
            }
        }
    }


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