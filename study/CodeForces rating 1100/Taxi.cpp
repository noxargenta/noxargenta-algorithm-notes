#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    vector<ll> cnt(5,0);
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        cnt[x]++;
    }
    ll ans=0;
    ans+=cnt[4];
    ll val=cnt[1]*1;
    ans+=val/4;
    val%=4;
    cnt[1]=val;
    val=cnt[2]*2;
    ans+=val/4;
    val%=4;
    cnt[2]=val;
    ll now=0;
    for(ll i=1;i<=3;i++){
        if(cnt[i]==0){
            continue;
        }
        if(now+i>4 && cnt[i]>0){
            ans++;
            now=i;
            cnt[i]--;
        }
        if(i==1){
            now+=cnt[i]*i;
        }
        
    }
    cout <<ans <<endl;
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