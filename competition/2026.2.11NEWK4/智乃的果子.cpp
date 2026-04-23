#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for(int i=1;i<=n;i++){
        int x,y;
        cin >> x >> y;
        q.push({y,x});
    }
    int ans=0;
    int mod=1000000000+7;
    while(1){
        auto u=q.top();
        q.pop();
        if(q.empty() && u.second==1){
            break;
        }
        int m=u.first;
        int c=u.second;
        int k=c/2;
        if(k){
            int temp=(m%mod)*(k%mod)*2%mod;
            ans=(ans+temp)%mod;
            q.push({m*2,k});
        }
        if(c%2!=0){
            auto u2=q.top();
            q.pop();
            ans=((ans+m)%mod+u2.first%mod)%mod;
            q.push({m+u2.first,1});
            if(u2.second>1){
                q.push({u2.first,u2.second-1});
            }
        }
    }
    cout << ans << endl;
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