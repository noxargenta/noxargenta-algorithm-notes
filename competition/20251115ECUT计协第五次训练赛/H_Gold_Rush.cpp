#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

bool check(int c,int m){
    int n1=c*1/3;
    int n2=c*2/3;
    if(c==m){
        return 1;
    }else if(c<m){
        return 0;
    }else {
        if(c%3!=0){
            return 0;
        }else if(n1==m || n2==m){
            return 1;
        }else {
            bool temp=check(n1,m);
            if(temp){
                return 1;
            }else {
                return check(n2,m);
            }
        }
    }
}

void solve() {
    int n,m;
    cin >> n>>m;
    if(check(n,m)){
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