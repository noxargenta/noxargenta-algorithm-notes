#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    int nn=n/2,mm=m/2;
    if(nn*mm>k || k>n*m-nn*mm){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    vector<string> a(n,string('0',m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==1 && j%2==1){
                a[i][j]='1';
                k--;    
            }

        }
    }
    int ok=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='0' && k!=0){
                a[i][j]='1';
                k--;
            }
            if(k==0){
                ok=1;
            }
            if(ok==1)break;
        }
        if(ok==1)break;
    }
    for(int i=0;i<n;i++){
        cout << a[i] << endl;
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