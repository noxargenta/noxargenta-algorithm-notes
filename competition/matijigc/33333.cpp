#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
struct xy{
    int x;
    int y;
};
bool check(int lx1,int ly1,int rx1,int ry1,int lx2,int ly2,int rx2,int ry2){
    if(rx2<=rx1-lx2+rx2 && rx2>=lx1 && ry2<=ry1-ly2+ry2 && ry2>=ly1){
        return 1;
    }
    return 0;
}
void solve() {
    int n;
    cin >> n;
    vector<xy> l(n+1);
    vector<xy> r(n+1);

    for(int i=1;i<=n;i++){
        cin >>l[i].x >> l[i].y >> r[i].x >> r[i].y;
    }
    for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(check(l[i].x,l[i].y,r[i].x,r[i].y,l[j].x,l[j].y,r[j].x,r[j].y)){
                ans++;
            }
        }
        cout << ans << " ";
    }
    cout <<endl;
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