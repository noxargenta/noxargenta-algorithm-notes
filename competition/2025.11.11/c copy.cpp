#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=0;i<=n;i++){
        a[i]=i;
    }
    if(n%2==0){
        int n2=0;
        double x=n;
        for(;x!=1;n2++){
            x=ceil(x/2.0);
        }
        cout << n-3+n2<<endl;
        for(int i=3;i<n;i++){
            cout << i << " " << i+1 << endl;
        }
        for(int i=0;i<n2;i++){
            cout << n << " " << 2 <<endl;
        }
    }else {
        int n2=0;
        double x=n-1;
        for(;x!=1;n2++){
            x=ceil(x/2.0);
        }
        cout << n-3+n2-1 +2<<endl;
        for(int i=3;i<n-1;i++){
            cout << i << " " << i+1 << endl;
        }
        cout << n << " "<<n-1<<endl;
        cout << n<<" "<<2<<endl;
        if(n-1>2){
            for(int i=0;i<n2;i++){
            cout << n-1 << " " << 2 <<endl;
            }
        }
    }
    
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