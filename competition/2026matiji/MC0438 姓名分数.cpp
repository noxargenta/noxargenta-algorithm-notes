#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n ;
    set<string> s;
    for(int i=1;i<=n;i++){
        string x;
        cin   >> x;
        s.insert(x);
    }
    cin >> m;
    map<string,int> ma;
    for(int i=1;i<=m;i++){
        int opt;
        cin >> opt;
        if(opt==1){
            string str;
            cin >> str;
            int x2;
            cin >> x2;
            if(!s.count(str)){
                continue;
            }
            ma[str]+=x2;
        }else {
            string s2;
            cin >> s2;
            
            if(!s.count(s2)){
                cout << -1 << endl;
            }else {
                cout << ma[s2] << endl;
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