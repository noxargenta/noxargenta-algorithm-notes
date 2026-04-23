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
    int ans=0;
    int last=-1;
    sort(a.begin(),a.end(),greater());
    for(int i=0;i<n;i++){
        if(a[i]==last){
            ans+=a[i];
            continue;
        }
        int x=0;
        for(int j=i+1;j<n;j++){
            if(a[j]<=a[i]){
                x++;
            }
        }
        if(x-(n-1)*0.8>=0){
            ans+=a[i];
            last=a[i];
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