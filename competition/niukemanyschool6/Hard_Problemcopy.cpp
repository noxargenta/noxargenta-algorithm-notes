#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
void solve() {
    ll n;
    cin >> n;
    vector<ll> a;
    for(ll i=1;i<=n;i++){
        a.push_back(i);
    }
    do{
        bool ok=1;
        for(int i=0;i<n;i++){
            ll dif=abs(a[i]-a[()]);
            if(isPrime(dif)){
                ok=0;
            }
            if(ok==0){
                cout << "-1" <<endl;
                return;
            }
        }
        if(ok){
            cout << "n:" << n << endl;
            for(auto x : a){
                cout << x << " ";
            }cout << endl;
            return;
        }
    }while(next_permutation(a.begin(),a.end()));
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    //cin >> _;
    while(1) {
        solve();
    }
    return 0;
}