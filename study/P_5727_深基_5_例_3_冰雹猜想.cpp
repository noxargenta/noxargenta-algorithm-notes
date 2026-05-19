#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a;
    while(true){
        a.push_back(n);  
        if(n==1){
            break;
        }
        if(n & 1){
            n=n*3+1;
        }else {
            n/=2;
        }
          
        
    }
    for(int i=a.size()-1;i>=0;i--){
        cout << a[i] << ' ';
    }
    cout << endl;
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