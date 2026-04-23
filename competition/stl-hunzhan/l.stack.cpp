#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    string s;
    cin >>s;
    int current_num=0;
    int i=0;
    int total=0;
    for(;i<s.length() && isdigit(s[i]);i++){
        current_num=(current_num*10+(s[i]-'0'))%10000;
    }
    int one_num=current_num;
    current_num = 0;
    while(i<s.length()){
        char x=s[i];
        i++;
        while (i < s.length() && isdigit(s[i])) {
            current_num=(current_num*10 +(s[i]-'0'))%10000;
            i++;
        }
        if(x=='+'){
            total=(total+one_num)%10000;
            one_num=current_num;
        }else if(x=='*'){
            one_num=(one_num*current_num)%10000;
        }
        current_num = 0;
    }
    total=(total+one_num)%10000;
    cout << total << endl;
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