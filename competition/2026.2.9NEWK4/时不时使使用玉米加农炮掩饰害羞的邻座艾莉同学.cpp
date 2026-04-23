#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m ,q;
    cin >> n >> m >> q;
    array<int,3> ma={0,0,0};
    vector<vector<int>> a(n+1,vector<int> (m+1));
    vector<vector<int>> b(n+1,vector<int> (m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int t;
            cin >> t;
            for(int dx=-2;dx<=2;dx++){
                int k=2-abs(dx);
                for(int dy=-k;dy<=k;dy++){
                    int x=i+dx;
                    int y=j+dy;
                    if(x<1||x>n||y<1||y>m)continue;
                    b[x][y]+=t;
                    ma=max(ma,{b[x][y],x,y});
                }
            }
        }
    }
    while(q--){
        int x,y,z;
        cin >> x >> y >> z;
        for(int dx=-2;dx<=2;dx++){
            int k=2-abs(dx);
            for(int dy=-k;dy<=k;dy++){
                int xx=x+dx;
                int yy=y+dy;
                if(xx<1||xx>n||yy<1||yy>m)continue;
                b[xx][yy]+=z;
                ma=max(ma,{b[xx][yy],xx,yy});
            }
        }
        cout << ma[1] << " " << ma[2] << endl;
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