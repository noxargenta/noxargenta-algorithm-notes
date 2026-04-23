#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const int MAX=200005;
vector<int> tu[MAX];
int input[MAX],pos[MAX],bfs_res[MAX];
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        tu[x].push_back(y);
        tu[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        cin >> input[i];
        pos[input[i]]=i;
    }
    for(int i=1;i<=n;i++){
        sort(tu[i].begin(),tu[i].end(),[&](int x,int y){
            return pos[x]<pos[y];
        });
    }
    queue<int> q;
    int len=0;
    q.push(1);
    while(!q.empty)
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