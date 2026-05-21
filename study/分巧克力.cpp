#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    int minn=1000000;
    int maxx=0;
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
        minn = min(a[i].first,a[i].second);
        maxx=max(minn,maxx);
    }
    auto  ok = [&](int x) ->bool{
        int sum=0;
        for(int i=0;i<n;i++){
            int s1=a[i].first*a[i].second;
            int s2=x*x;
            int num=(a[i].first/x)*(a[i].second /x);
            sum+=num;
        }
        if(sum>=k){
            return 1;
        }else {
            return 0;
        }
    };
    int l=1,r=100000;
    while(l<r){
        int mid=(l+r +1 )/2;
        if(ok(mid)){
            l = mid;
        }else {
            r = mid - 1;
        } 
    }
    cout << r << endl;
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