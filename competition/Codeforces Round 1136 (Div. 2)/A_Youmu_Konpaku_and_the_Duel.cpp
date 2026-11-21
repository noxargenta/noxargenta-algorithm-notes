#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll x;
    cin >> x;
    ll ans=x;
    for(ll c=0;c<ans;c++){
        ll hp=x;
        ll cnt=c;
        ll atk=c+1;
        while(hp>0 && cnt < ans){
            cnt++;
            hp-=atk;
            atk=max(1LL,atk-1);
        }
        if(hp<=0)ans=min(ans,cnt);
    }
    cout << ans << endl;
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