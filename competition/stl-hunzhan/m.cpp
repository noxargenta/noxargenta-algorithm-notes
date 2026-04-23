#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,renum=1,count=0;
    cin >> n;
    stack<int> a;
    for(int i=0;i<n*2;i++){
        string st;
        cin >> st;
        if(st=="add"){
            int x;
            cin >> x;
            a.push(x);
        }else if(st=="remove" && !a.empty()){
            if(a.top()==renum){
                a.pop();
            }else if(a.top()!=renum && !a.empty()){
                count++;
                while(!a.empty()){
                    a.pop();
                    renum++;
                }
            }else if(a.empty()){
                continue;
            }
        }
    }
    cout << count;
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