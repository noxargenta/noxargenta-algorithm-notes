#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    vector<int> s(n);
    int a[n];
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        s[i]=x;
        if(x%2==0){
            a[i]=2;
        }else {
            a[i]=1;
        }
    }
    for(int i=0;i<n;i+=2){
        int c=a[0];
        if(a[i]!=c){
            cout << "NO"<<endl;
            return;
        }
    }
    for(int i=1;i<n;i+=2){
        int c=a[1];
        if(c!=a[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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