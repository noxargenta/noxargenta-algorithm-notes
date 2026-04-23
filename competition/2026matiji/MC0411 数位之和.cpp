#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve(){
    int n;
    cin >> n;
    string s;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin >> s;
        for(int x:s){
            ans+=(x-'0');
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false );
    cin.tie(nullptr);
    int _=1;
    //cin >>_;
    while(_--){
        solve();
    }

}