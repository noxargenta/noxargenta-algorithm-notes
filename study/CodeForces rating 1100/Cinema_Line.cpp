#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    
    map<ll,ll> mp;
    while(n--){
        ll x;
        cin >> x;
        ll need=x-25;
        if(need==0){
            mp[x]++;
        }else if(need==25){
            if(mp[25]==0){
                cout << "NO\n";
                return;
            }else {
                mp[x++];
                mp[25]--;
            }
        }else{
            if(mp[25]>=3){
                mp[25]-=3;
                mp[100]++;
            }else if(mp[25]>=1 && mp[50]>=1){
                mp[100]++;
                mp[25]--;
                mp[50]--;
            }else {
                cout << "NO\n";
                return;
            }

        }
    }
    cout << "YES\n";
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