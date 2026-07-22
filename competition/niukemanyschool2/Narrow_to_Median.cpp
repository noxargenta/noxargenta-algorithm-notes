#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1,0);
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;i++){
        cin >>a[i];
        pre[i]=pre[i-1]+a[i];
    }   
    int maxc=-INT_MAX;
    sort(a.begin()+1,a.end());
    if(k%2==1){
        int m=(k-1)/2;
        int sum1=pre[m]-pre[0];
        for(int i=)
    }

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