#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int a2=20260606,a1=20000000;
void solve() {
    unordered_set<int> st;
    string s;
    for(int i=a1;i<=a2;i++){
        s=to_string(i);
        for(int pos=0;pos<(int)s.size();pos++){
            for(char c='0';c<='9';c++){
                if(c=='0' && pos==0)continue;
                string t=s;
                t.insert(t.begin()+pos,c);
                if(t[0]=='1' || t[1]=='1')continue;
                st.insert(stoll(t));
            }
        }
    }
    cout << 99999990 + 180000000 + st.size() <<endl;
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