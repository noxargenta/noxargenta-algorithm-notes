#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int l=0,r=0;
            
            for(int k=0;k<n;k++){
                if(k==i || k==j)continue;
                int cc=(a[j].first-a[i].first)*(a[k].second-a[i].second)-(a[k].first-a[i].first)*(a[j].second-a[i].second);
                if(cc>0){
                    l++;
                }
                if(cc<0){
                    r++;
                }
                
            }   
            if(l==r){
                ans++;
            }
        }

    }
    cout << ans <<endl;
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