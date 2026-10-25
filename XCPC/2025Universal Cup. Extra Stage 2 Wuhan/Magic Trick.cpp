#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    for(ll i=0;i<n;i++){
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll j1=0;
    ll j2=0;
    bool cha1=0;
    bool cha2=0;
    bool ok=1;
    for(ll i=0;i<n;i++){
        if(a[i]%2==1){
            j1++;
        }
        if(b[i]%2==1){
            j2++;
        }
        if(a[i]!=b[i]){
            ok=0;

        }
        if(i> 0){
            if(abs(a[i]-a[i-1])==1){
                cha1=1;
            }
            if(abs(b[i]-b[i-1])==1){
                cha2=1;
            }
        }
    }
    if(ok==1){
        cout << "Yes\n";
        return;
    }
    if(cha1!=0 && cha2!=0 && j1==j2){
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
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