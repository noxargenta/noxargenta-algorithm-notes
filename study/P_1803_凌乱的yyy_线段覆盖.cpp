#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >>n;
    vector<pair<int,int>> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i].first >> a[i].second;
    }
    if(n==1){
        cout << 1 << endl;
        return ;
    }
    sort(a.begin()+1,a.end(),[&](pair<int,int> x,pair<int,int> y){
        if(x.second!=y.second){
            return x.second<y.second;
        }else {
            return x.first<=y.first;
        }
    });
    int ans=1;
    int j=1;
    for(int i=2;i<=n;i++){
        int x1=a[j].first;
        int y1=a[j].second;
        int x2=a[i].first,y2=a[i].second;
        if(x2>=y1){
            j=i;
            ans++;
        }
    }
    cout << ans << endl;
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