#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int n,m;
struct p{
    int d,s,t;
};
vector<int> a;
vector<p> pe;
bool check(int mid){
    vector<i64> diff(n+2,0);
    for(int i=1;i<=mid;i++){
        diff[pe[i].s]+=pe[i].d;
        diff[pe[i].t+1]-=pe[i].d;
    }
    i64 sum=0;
    for(int i=1;i<=n;i++){
        sum+=diff[i];
        if(sum>a[i]){
            return 0;
        }
    }
    return 1;
}
void solve() {
    cin >> n >> m;
    a.resize(n+1);
    pe.resize(m+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> pe[i].d >> pe[i].s >> pe[i].t;
    }
    int l=1,r=m;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    if(l>m){
        cout << "0" << endl;
    }else{
        cout << "-1" << endl << l << endl;
    }
}
signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while(_--) {
        solve();
    }
    return 0;
}