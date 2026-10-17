#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+1,0);
    vector<ll> b(m+1,0);
    
    vector<ll> difa(n+1,0);
    vector<ll> difb(n+1,0);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        difa[i]=a[i]-a[i-1];
    }
    for(ll i=1;i<=m;i++){
        cin>> b[i];
        difb[i]=b[i]-b[i-1];
    }
    ll ans=0;
    auto kmp = [&](vector<ll> s,vector<ll> p) -> void{
        ll nn=m+1;
        ll mm=n+1;
        ll i,j;
        vector<ll> next(nn+1);
        
        j=next[1]=-1;
        i=1;
        while(i<mm){
            while(j!=-1 && s[i]!=s[j]){
                j=next[j];
            }
            next[++i]=++j;
        } 
        i=j=0;
        while(i<nn){
            while(j!=-1 && s[j]!=p[i]){
                j=next[j];
                if(j>=nn){
                    ans++;
                    j=next[j];
                }
            }
        }
        return;
    };
    kmp(difb,difa);
    cout << ans <<endl;
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