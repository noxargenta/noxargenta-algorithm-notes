#include <bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    int ansa=0;
    int ansb=0;
    for(int i=1;i<=n;i++){
        ansa=(ansa+a[i])%2;
        ansb=(ansb+b[i])%2;
        
    }
    if(ansa*ansb%2==0){
        cout << "even\n";
    }else {
        cout << "odd\n";
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    //cin >> _;
    while(_--){
        solve();
    }
}