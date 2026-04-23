#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    string s;
    vector<int> vi(n+1,0),ans(n+1,0);
    cin >> s;
    for(int i=1;i<=n;i++){
        int sum=0;
        while(vi[i]==0){
            vi[i]=1;
            sum+=s[i-1]=='0';
            i=a[i];
        }
        while(vi[i]==1){    
            vi[i]=2;
            ans[i]=sum;
            i=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
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