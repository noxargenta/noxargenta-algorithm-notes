#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct ping
{
    int id;
    int jiage;
    double v=1;
    double jun;
};

void solve() {
    int n,l;
    cin >> n >> l;
    vector<ping> pingzi(n);
    for(int i=0;i<n;i++){
        pingzi[i].id=i;
        cin >> pingzi[i].jiage;
        for(int j=0;j<n;j++){
            pingzi[i].v*=2;
        }
        pingzi[i].jun=pingzi[i].v*1.0000000000/pingzi[i].jiage;
    }
    sort(pingzi.begin(),pingzi.end(),[](ping&a,ping&b){
        return a.jun>b.jun;
    });
    int result=0,vr=0;
    for (int i=0;;i++){
        vr+=pingzi[0].v;
        result+=pingzi[0].jiage;
        if(vr>=l){
            cout << result;
            return;
        }
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