#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,c;
    cin >> n >> c;
    vector<int> a(n,0);
    
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=(a[i]-c);
    }
    sort(a.begin(),a.end());
    int ans=sum;
    for(int i=0;i<(n/2);i++){
        int d=c-a[i];
        if(d>0){
            ans+=d;
        }else {
            break;
        }
    }
    cout << ans << endl;
    
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