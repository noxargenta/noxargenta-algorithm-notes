#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int h,w;
    cin >> h >> w;
    vector<string> g(h);
    for(int i=0;i<h;i++){
        cin >> g[i];
    }
    int dx[8]={0,-1,0,1,-1,-1,1,1};
    int dy[8]={-1,0,1,0,-1,1,1,-1};
    map<char,int> mp;
    mp['s'] = 0;
	mp['n'] = 1;
	mp['u'] = 2;
	mp['k'] = 3;
	mp['e'] = 4;
    vector<array<int,2>> point(5);
    auto check = [&](int x,int y) -> bool{
        for(int i=0;i<8;i++){
            bool ok=true;
            for(int j=0;j<5;j++){
                int a=x+ j*dx[i],b=y+j*dy[i];
                ok&=(a >= 0 && a < h && b >= 0 && b < w && mp[g[a][b]] == j);
                point[j]={a,b};
            }
            if(ok){
                for(auto [a,b] : point){
                    cout << a + 1 << ' ' << b + 1 << endl;
                }
                return true;
            }
        }
        return false;
    };
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)if(g[i][j]=='s'){
            if(check(i,j)){
                return;
            }
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