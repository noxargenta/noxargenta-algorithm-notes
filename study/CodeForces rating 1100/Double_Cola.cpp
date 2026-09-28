#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
string s[]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
ll pox(ll n){
    ll ans=0;
    for(ll i=0;i<=n;i++){
        ans+=pow(2,i)*5;
    }
    return ans;
}
void solve() {
    ll n;
    cin >> n;
    ll i=0,j=0;//i第i段，j是第i段的第j个
    while(pox(i)<n){
        i++;
    }
    j=n-pox(i-1)-1;
    j/=(ll)round(pow(2,i));
    cout << s[j]<<endl;
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