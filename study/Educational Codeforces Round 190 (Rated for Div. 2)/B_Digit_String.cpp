#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    string s;
    cin  >> s;
    int i2=-1;
    int a[5]={0};
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]-'0'==4){
            a[4]++;
        }
        if(s[i]-'0'==2 && i2==-1){
            i2=i;
        }
        if(i2!=-1){
            a[s[i]-'0']++;
        }
    }
    cout << min((a[1]+a[3]),a[2]) + a[4] << endl;
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
}// 32 12 4 44
