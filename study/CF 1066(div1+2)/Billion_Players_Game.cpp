#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n ,l,r;
    cin >> n >> l >> r;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int sum=0;
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        if(a[i]<l){
            sum+=l-a[i];a[i]=l;

        }else if(a[i]>r){
            sum+=a[i]-r;a[i]=r;
        }
    }
    for(int i=1,j=n;i<=j;i++,j--){
        sum+=a[j]-a[i];
    }
    cout << sum<< endl;
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