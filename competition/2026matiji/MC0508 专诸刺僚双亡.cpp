#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1);
    
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<int> cnt(1000005, 0); 
    while(q--){
        int l,r;
        cin >> l >> r;
        //map<int,int> m;
        int ans=0;
        for(int i=l;i<=r;i++){
            cnt[a[i]]++;
            if(cnt[a[i]]>ans){
                ans=cnt[a[i]];
            }
        }
        for(int i=l;i<=r;i++){
            cnt[a[i]]=0;
        }
        cout << ans << endl;
    }

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