#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    string s;
    cin >> s;
    string ans;
    ll n=s.length();
    for(ll i=0;i<n;i++){
        if(s[i]=='-'){
            if(ans.size()>=1){
                ans.pop_back();
            }
            continue;
        }
        if(ans.size()>=1 && s[i] == ans.back()){
            continue;
        }
        if(ans.size()>=2 && s[i]== ans[ans.size()-2]){
            continue;
        }
        ans+=s[i];
    }
    if(ans.empty()){
        cout << "-\n";
        return;
    }
    cout << ans <<endl;
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