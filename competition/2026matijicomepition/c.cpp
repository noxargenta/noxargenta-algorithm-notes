#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF=0x3f3f3f3f;
const int INFLL=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i].first >> a[i].second;
    }
    int ans=INFLL;
    for(int i=1;i<=n;i++){
        int val=0;
        for(int j=1;j<=n ;j++){
            if(i==j)continue;
            val=max(val,abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second));
            //cout << val << endl;
            
        }
        ans=min(val,ans);
    }
    cout << ans << endl;
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