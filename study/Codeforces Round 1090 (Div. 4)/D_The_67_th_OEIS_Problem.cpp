#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int n;
int m=0;
const int N=1e6+10;
vector<int> p(N);
vector<int> a(N);
bool isPrime(int x){
    if(x<2){
        return 0;
    }else {
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                return 0;
            }
        }
        return 1;
    }
}
void solve() {
    cin >> n;
    for(int i=1;i<=n;i++){
        a[i]=p[i-1]*p[i+1];
    }
    for(int i=1;i<=n;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    int now=1;
    p[0]=1;
    while(true){
        if(isPrime(now)){
            p.push_back(now);
            now++;
            m++;
        }
        if(m>20000){
            break;
        }
    }
    while(_--) {
        solve();
    }
    return 0;
}