#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,c;
    cin >> n >> c;
    
    int suma=0;
    int sumb=0;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        suma+=a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        sumb+=b[i];
    }
    bool ok=1;
    for(int i=0;i<n;i++){
        if(a[i]<b[i]){
            ok=0;
        }
    }
    if(ok==1){
        cout << suma - sumb <<endl;
        return;
    }

    int ans=c;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        if(a[i]-b[i]>=0){
            ans+=a[i]-b[i];
        }else {
            cout << -1 <<endl;
            return;
        }
    }
    cout << ans <<endl;
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