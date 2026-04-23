#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int n,m;

struct p{
    int d,s,t;
};
bool check(int mid.){
    int sum=0;
    for(int i=1;i<=pe[mid].t;i++){
        sum+=a[i];
        if(sum<0){
            return 0;
        }
    }
    return 1;
}
void solve() {
    vector<p> pe(m+1);
    vector<int> a(n+1); 
    cin >> n >> m;
    cin >> a[1];
    for(int i=2;i<=n;i++){
        int t;
        cin >> t;
        a[i]=t-a[i-1];
    }
    int d,s,t;
    for(int i=1;i<=m;i++){
        cin >>  d >> s >> t;
        pe[i].d=d;
        pe[i].s=s;
        pe[i].t=t;
        a[s]-=d;
        a[t+1]+=d;
    }
    int l=1;
    int r=1000000+9;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }else {
            r=mid-1;
        }
    }
    if(l>m){
        cout << "0";
        return;
    }else {
        cout << "-1\n"<<l;
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