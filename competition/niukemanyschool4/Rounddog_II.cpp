#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll t=0;
    cin >> t;
    string ini="Rounddo";
    string st=ini+string(t,'g');
    ll cnt=0;
    for(ll i=0;i+st.length()<=s.length();i++){
        if(s.substr(i,st.length())==st){
            cnt++;
        }
    }
    if(cnt==0){
        cout << 0<<endl;

    }else if(cnt==1){
        cout << s.length()-t-6 <<endl;
    }else{
        cout << s.length();
    }
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