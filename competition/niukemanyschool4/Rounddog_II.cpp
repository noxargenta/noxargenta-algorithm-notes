#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    string s;
    cin >> s;
    ll t=0;
    cin >> t;
    string ini="Rounddo";
    string ss=s+s;
    string st=ini+string(t,'g');
    ll cnt=0;
    for(ll i=0;i<s.length() && i+st.length()<ss.length();i++){
        if(ss.substr(i,st.length())==st){
            cnt++;
        }
    }
    if(cnt==0){
        cout << 0<<endl;
    }else if(cnt==1){
        //cout << "st.length()" << st.length() <<endl;
        cout << s.length()-st.length()+1 <<endl;
    }else{
        cout << s.length() <<endl;
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