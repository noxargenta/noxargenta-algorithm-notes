#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll n;
vector<ll> a;
unordered_map<ll,ll> cnt;
unordered_map<ll,ll> best;
vector<ll> small;
ll calc(ll k){
    ll ans=n;
    for(ll x=0;x<n;x ++ ){
        if(x>ans){
            break;
        }
        ll y=k-x;
        ll cntx=0,cnty=0;
        
        if(cnt.count(x)){
            cntx=cnt[x];
        }
        if(cnt.count(y)){
            cnty=cnt[y];
        }
        if(cntx+cnty==0){
            ll cur=x;
            if(y>0){
                cur=min(x,y);
            }
            ans=min(ans,cur);
        }else if(cntx + cnty ==1 && x < y && y<n){
            ans=min(ans,y);
        }
    }
    return ans;
}
ll mex(){
    vector<ll> vis(n+1,0);
    for(auto x : a){
        if(x>=0 && x <=n){
            vis[x]=1;
        }
    }
    for(ll i=0;i<=n;i++){
        if(!vis[i]){
            return i;
        }
    }
    return n;
}
void solve() {
    cin >> n;
    a.resize(n);
    small.resize(n);
    cnt.clear();
    best.clear();
    for(ll i=0;i<n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll M=mex();
    for(auto ai : a){
        ll k=M+ai;
        if(!best.count(k)){
            best[k]=calc(k);
        }
    }
    ll res=0;
    ll q;
    cin >> q;
    while(q--){
        ll k;
        cin >> k;
        ll x=k-M;
        if(x<0 || !cnt.count(x)){
            res^=M;
        }else {
            res^=best[k];
        }
    }
    cout << res << endl;
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