#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    stack<string> a;
    for(string t;t!="@";){
        cin >>t;
        if(t=="."){
            continue;
        }
        if (t!="+" && t!="*" && t!="-" && t!="/"){
            a.push(t);
        }else{
            string s1=a.top();a.pop();
            string s2=a.top();a.pop();
            int result=0;
            int x1=stoi(s1);
            int x2=stoi(s2);
            if (t=="+"){
                result=x1+x2;
            }else if(t=="-"){
                result=x2-x1;
            }else if(t=="*"){
                result=x1*x2;
            }else if(t=="/"){
                result=x2/x1;
            }
            a.push(to_string(result));
        }
    }
    cout << a.top();
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