#include <bits/stdc++.h>
using namespace std;
using i64 = unsigned long long;
void solve() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> a;
    for (int i=0;i<n;i++){
        int x=0;
        cin  >>  x;
        if(x==1){
            int t;
            cin >> t;
            a.push(t);
        }else if(x==2){
            cout << a.top() << endl;
        }else if(x==3){
            a.pop();
        }
    }
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