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
    
    vector<ll> difa(n,0);
    vector<ll> difb(m,0);
    for(ll i=1;i<n;i++){
        cin >> a[i];
        difa[i-1]=a[i+1]-a[i];
    }
    for(ll i=1;i<m;i++){
        cin>> b[i];
        difb[i-1]=b[i+1]-b[i];
    }
    if(m==1){
        cout << n  << endl;
        return;
    }

    ll ans=0;
    auto kmp = [&](vector<ll> s,vector<ll> p) -> void{
        ll nn=m+1;/////nn  s
        ll mm=n+1;/////mm  p长串
        // ms//np
        ll i,j;
        vector<ll> nxt(m+1);
        
        j=nxt[0]=-1;
        i=0;
        while(i<m){
            while(j!=-1 && s[i]!=s[j]){
                j=nxt[j];
            }
            nxt[++i]=++j;
        } 
        i=j=0;
        while(i<n){
            while(j!=-1 && s[j]!=p[i]){
                j=nxt[j];
            }
            i++;j++;
            if(j>=m){
                ans++;
                j=nxt[j];
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