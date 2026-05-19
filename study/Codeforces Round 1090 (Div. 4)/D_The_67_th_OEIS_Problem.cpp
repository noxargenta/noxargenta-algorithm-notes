#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int n;
int m=0;
int N=
int p[]
bool isPrime(int x){
    if(x<2){
        return 0;
    }else {
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                return 0;
            }
        }
        return 1;
    }
}
void solve() {
    cin >> n;

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