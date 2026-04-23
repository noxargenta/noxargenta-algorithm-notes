#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    stack<string> a;
    string s;
    cin >>s;
    string c="";
    for (auto x : s){
        if (isdigit(x)){
            c+=x;
        }else if(!c.empty()){//"."
            a.push(c);
            c="";
        }
        if (x=='.'){
            continue;
        }else if(x=='@'){
            break;
        }else if (x == '+' || x == '-' || x == '*' || x == '/') {
            string s1=a.top();a.pop();
            string s2=a.top();a.pop();
            i64 result=0;
            i64 x1=stoll(s1);
            i64 x2=stoll(s2);
            if(x=='+'){
                result=x1+x2;
            }else if(x=='-'){
                result=x2-x1;
            }else if(x=='*'){
                result=x1*x2;
            }else if(x=='/'){
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