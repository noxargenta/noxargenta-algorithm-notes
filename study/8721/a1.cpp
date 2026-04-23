#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    string s;
    cin >>s;
    priority_queue<int> a2;
    for(int i=0;i<s.size();i++){
        a2.push(s[i]);
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!=a2.top()){
            //s[0]=a2.top();
            for(int j=s.size()-1;j>i;j--){
                if(s[j]==a2.top()){
                    swap(s[i],s[j]);
                    cout << s << "\n";
                    return;
                }
            }
        }else  {
            a2.pop();
        }
    }
    cout << s << "\n";
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