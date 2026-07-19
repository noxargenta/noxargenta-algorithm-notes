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
    bool inv=0;
    if(k>n*m/2){
        inv=1;
        k=n*m-k;
    }
    char a,b;
    if(inv){
        a='1';
        b='0';
    }else{
        a='0';
        b='1';
    }
    vector<string> s(n,string(m,a));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==1 && j%2==1){
                s[i][j]=b;
                k--;    
            }

        }
    }
    int ok=0;
    if(k==0)ok=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]==a && k!=0 && !(i%2==0 && j%2==0)){
                s[i][j]=b;
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
        cout << s[i] << endl;
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