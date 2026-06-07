#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin >>b[i];
    }
    sort(b.begin(),b.end(),greater<int>());
    
    if(n==2){
        cout << b[0] << " "<< b[1] << endl;
        return;
    }
    for(int i=1;i<n-1;i++){
        if(b[i]==b[i+1]){
            cout << -1 << endl;
            return;
        }
    }
    for(int i=1;i<n-1;i++){
        if(b[i+1]!=b[i-1]%b[i]){
            cout << -1 << endl;
            return;
        }
    }
    cout << b[0] <<" "<< b[1] << endl;
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