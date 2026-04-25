#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int last=0;
    if(a[0]!=0){
        cout << 0 << endl;
        return ;
    }
    for(auto x:a){
        if(x!=last+1 && x!=0 && x!=last){
            cout  << last+1 << endl;
            return;
        }
        last=x;
    }
    cout << a[n-1]+1<< endl;
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