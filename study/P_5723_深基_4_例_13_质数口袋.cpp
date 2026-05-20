#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
bool isPrime(int x){
    if(x<2){
        return 0;
    }
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
void solve() {
    int L;
    cin >> L;
    int sum=0;
    int n=0;
    vector<int> a;
    for(int i=2;;i++){
        
        if(isPrime(i)){
            if(sum+i>L){
                break;
            }
            sum+=i;
            a.push_back(i);
            n++;
        }
    }
    for(auto x : a){
        cout << x  << endl;
    }
    cout << n << endl;

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