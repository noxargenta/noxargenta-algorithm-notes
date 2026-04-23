#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    char x;
    int x1=0;
    int x0=0;
    vector<string> a(n+1);
    vector<int> b(256,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        for(char c : a[i]){
            b[(c-'0')]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].length();j++){
            if(b[(a[i][j]-'0')]>1){
                a[i][j]='Y';
            }else {
                a[i][j]='N';
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << a[i];
        cout << endl;
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