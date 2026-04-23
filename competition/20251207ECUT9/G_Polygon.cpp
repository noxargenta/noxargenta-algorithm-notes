#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        sum+=a[i];
    }
    
    sort(a.begin(),a.end());
    vector<int> b(n+1);
    for(int i=1;i<=n;i++){
        b[i]+=b[i-1]+a[i];
    }
    int j=n;
    while(j>=0){
        bool ok=0;
        if(j<=2){
            cout << "0\n" ;
            break;
        }
        if(b[j-1]>b[j]-b[j-1]){
            ok=1;
        }
        if(ok){
            cout << b[j] << endl;
            break;
        }else {
            j--;
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