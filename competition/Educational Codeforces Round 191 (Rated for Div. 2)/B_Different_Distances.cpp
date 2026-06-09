#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    vector<int> a={1,1,2,1,2,3,1,2,2,3,3,4,3,4,4,5,5,4,5};
    int n;
    cin >> n;
    n*=4;
    if(n>19){
        int m=n/4;
        for(int i=6;i<=m+6;i++){
            a.push_back(i);
            a.push_back(i);
            a.push_back(i-1);
            a.push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        cout << a[i] << " ";  
    }
    cout << endl;

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