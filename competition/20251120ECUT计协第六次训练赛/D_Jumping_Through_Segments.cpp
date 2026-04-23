#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n';
const int INF=2*100002;
#define int long long

vector<int> l(INF),r(INF);

bool check(int k,int n){
    int lef=0,rig=0;
    for(int i=1;i<=n;i++){
        lef-=k;
        rig+=k;
        if(lef>r[i] || rig<l[i]){
            return false;
        }else {
            lef=max(lef,l[i]);
            rig=min(rig,r[i]);
        }
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> l[i] >> r[i]; 
    }
    int res;
    int lx=0,rx=INF;
    while(lx<=rx){
        int mid=(lx+rx)/2;
        if(check(mid,n)){
            res=mid;
            rx=mid-1;
        }else {
            lx=mid+1;
        }
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