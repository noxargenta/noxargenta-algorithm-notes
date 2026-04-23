#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    string s;
    cin >> n >> s;
    int l=n-1;
    vector<int> a(n+1,-1);
    a[0]=0;
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            cnt++;
            a[cnt]=0;
            a[cnt]+=a[cnt-1]+l-i;
            l--;
        }
    }
    for(int i=1;i<=n;i++){
        if(i<=cnt){
            cout << a[i] <<" ";
        }else {
            cout << "-1 ";
        }
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