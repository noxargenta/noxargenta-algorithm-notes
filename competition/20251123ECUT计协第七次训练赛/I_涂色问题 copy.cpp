#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n+1);
    for(int i=0;i<n;i++){
        if(s[i]=='B'){
            a[i+1]=0;
        }else {
            a[i+1]=1;
        }
    }
    vector<int> b(n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
    if(b[n]==n){
        cout << k << endl;
        return;
    }
    int res=200005;
    for(int l=1;l<=n;l++){
        int r=l;
        if(a[l]==0){
            for(;r<=n&&a[r]==0;r++){
            }
            r--;
            if(r<k && n-l+1>=k){
                res=min(res,b[l+k-1]-b[l-1]);
                continue;
            }else if(n-l+1<k && r>=k){
                res=min(res,b[r]-b[r-k]);
                continue;
            }else if(n-l+1>=k && r>=k){
                res=min(res,b[r]-b[r-k]);
                res=min(res,b[l+k-1]-b[l-1]);
            }else {
                res=min(res,b[k]);
                res=min(res,b[n]-b[n-k]);
            }
        }
        l=r;
    }
    cout << res << endl;
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