#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll a,b,x,y,n;
    cin >> a >> b >> x >> y >> n;
    ll a2=a,b2=b,x2=x,y2=y,n2=n;
    ll val=min(a2-x2,n2);
    a2-=val;
    n2-=val;
    if(n!=0){
        val=min(b2-y2,n2);
        b2-=val;
        n2-=val;
    }
    ll ans=0;
    ans=max(a2*b2,ans);
    
    val=min(a-x2,n);
    a-=val;
    n-=val;
    if(n!=0){
        val=min(b-y,n);
        b-=val;
        n-=val;
    }
    ans=max(a*b,ans);
    cout << ans <<endl;
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
