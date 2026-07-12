#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
vector<int> G[(int)(2*1e5+2)];
void solve() {
    int n;
    cin >> n;
    int nn=n;
    set<int> st;
    while(nn--){
        int x,y;
        cin >> x  >> y;
        st.insert(x);
        st.insert(y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(auto x:st){
        //cout << G[x].size() << endl;
        if(G[x].size()!=2){
            cout << x << " ";
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