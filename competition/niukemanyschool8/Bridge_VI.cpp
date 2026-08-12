#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n,m;
    cin >> n  >> m;
    vector<ll> a(2*n,0);
    for( ll i=0;i<2*n;i++){
        cin >> a[i];
    }
    ll minans=0;
    ll maxans=0;
    for(ll i=0;i<2*n;i+=2){
        if(i==0)a[i]+=m;
        ll cnt=0;
        if(a[i]>a[0]){
            cnt++;
        }
        if(a[i+1]>a[0]){
            cnt++;
        }
        if(cnt==2){
            minans+=cnt;
        }else if(cnt==1){
            minans++;
        }else {
            if(a[0]*2-a[i]-a[i+1]>=m){
                continue;
            }else{
                minans++;
            }
        }
    }
    for(ll i=0;i<2*n;i+=2){
        if(i==0)a[i+1]+=m;
        ll cnt=0;
        if(a[i]>a[0]){
            cnt++;
        }
        if(a[i+1]>a[0]){
            cnt++;
        }
        if(cnt==2){
            maxans+=cnt;
        }else if(cnt==1){
            ll cha=max(a[0]-a[i],a[0]-a[i+1]);
            if(cha<m){
                maxans+=2;
                continue;
            }
            maxans++;
        }else {
            if(a[0]*2-a[i]-a[i+1]<m){
                maxans+=2;
                continue;
            }else if(min(a[0]-a[i],a[0]-a[i+1])<m){
                minans++;
            }else {
                continue;
            }
        }
    }
    cout << minans << " "<< maxans <<endl; 
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