#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<bool> c(n+1,0);
    
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    int x=1;
    int end_1=-1;
    for(int i=1;i<=n;i++){
        if(a[i]==b[x]){
            x++;
            c[i]=1;
        }
        if(x==m){
            end_1=i;
            break;
        }
    }
    if(end_1==-1){
        cout << "No";
        return;
    }
    int end_2=-1;
    int y=m;
    for(int i=n;i>=1;i--){
        if(a[i]==b[y] && c[i]==0){
            y--;
        }
        if(y==0){
            break;
        }
    }
    if(y==0 && x==m){
        cout << "Yes";
        return ;
    }else {
        cout << "No";
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