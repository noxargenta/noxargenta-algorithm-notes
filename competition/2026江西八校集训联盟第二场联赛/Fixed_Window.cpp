#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
map<ll,ll> xinhao;
//vector<ll> xinhao(2*(1e6)+10,0);
void solve() {
    ll n,L,k;
    cin >> n >> L >> k;
    vector<ll> a(n+1,0);
    vector<ll> w(n+1,0);
    ///vector<ll> prew(n+1,0);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    for(ll i=1;i<=n;i++){
        cin >> w[i];
        //prew[i]=prew[i]+w[i];
    }
    ll maxans=0;
    for(ll i=1;i<n;i++){
        xinhao[a[i]]+=w[i];
        maxans=max(maxans,xinhao[a[i]]);
        //cout << "deb" << maxans << endl;
    }
    ll l=1;
    ll r=l+L-1;
    for(ll i=l;i<=r;i++){
        xinhao[a[i]]-=w[i];
        a[i]+=k;
        xinhao[a[i]]+=w[i];
        maxans=max(maxans,xinhao[a[i]]);
        //cout << "deb" << maxans << endl;
    }
    for(ll i=l;i<=r;i++){
        maxans=max(maxans,xinhao[a[i]]);
    }
    l++;
    r++;
    for(;r<=n;r++,l++){
        xinhao[a[l-1]]-=w[l-1];
        a[l-1]-=k;
        xinhao[a[l-1]]+=w[l-1];
        
        xinhao[a[r]]-=w[r];
        a[r]+=k;
        xinhao[a[r]]+=w[r];
        maxans=max(maxans,xinhao[a[r]]);
        maxans=max(maxans,xinhao[a[l-1]]);
        maxans=max(maxans,xinhao[a[l-1]+k]);
        maxans=max(maxans,xinhao[a[r]-k]);
        //cout << "deb" << maxans << endl;
    }
    cout << maxans << endl;

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