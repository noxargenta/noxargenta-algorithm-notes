//11 22 33 44 55 66 77 88 99 110 121
//122 133 144
//1122 1133 1144;
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    string s;
    cin >> s;
    int x=stoll(s);
    int n=s.length()-1;
    int now=1;
    for(int i=0;i<n;i++){
        now*=10;
        now++;
    }
    while(x>=11 && now>=11){
        //cout << x << " "<<now<<endl;
        if(x>=now){
            x%=now;
            //cout << x << endl;
        }else {
            //cout <<"now" <<now<<endl;
            now/=10;
            //cout <<"now" <<now<<endl;
        }
    }
    if(x%10==0){
        cout << "YES\n";
    }else {
        cout << "NO\n";
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