#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int N=250005;
int fa[N];
int sz[N];
int mx[N];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
void solve() {
    int n,m,q;
    cin >> n >> m >> q;
    int sum=n*m;
    for(int i=1;i<=sum;i++){
        fa[i]=i;
        sz[i]=1;
        mx[i]=0;
    }
    vector<int> siz(sum+5,-1);//初始鱼大小;
    int last=0;
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int xp,yp,v;
            cin >> xp >> yp >> v;
            int x=xp^last;
            int y=yp^last;
            int id=(x-1)*m+y;
            siz[id]=v;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<1 || nx > n || ny<1 || ny>m)continue;
                int nid=(nx-1)*m+ny;
                if(siz[nid]!=-1){
                    int rnid=find(nid);
                    int rnow=find(id);
                    if(rnid!=rnow){
                        merge(rnow,rnid,v);
                    }
                }
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