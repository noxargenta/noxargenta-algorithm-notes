#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,c;
    cin >> n >> c;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> b[i];
        if(a[i]>b[i]){
            sum+=a[i]-b[i];
        }else if(a[i]<b[i]){
            sum=LLONG_MAX;
            break;
        }
    }
    int ans=c;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
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