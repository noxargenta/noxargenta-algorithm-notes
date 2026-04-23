#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
    int n,q;
        int te;
    int sum=0;
vector<int> a(n+1),b(n+1,-1);
int find(int x){
    int l=1,r=q;
    while(l<=r){
        int mid=(r+l)/2;
        if(   )
    }
}
void solve() {

    cin >> n >> q;

    for(int i=1;i<=n;i++){
        cin  >> a[i];
        sum+=a[i];
        if(i==1){
            te=a[i];
        }
        if(a[i]>te){
            b[te]=sum-a[i];
        }
        te=max(a[i],te);
    }
    int temp;
    for(int i=1;i<=n;i++){
        cin >> temp;

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