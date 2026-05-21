#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    set<int> s;
    int x=1;
    int last=2*n;
    int sum=1;
    s.insert(last);
    while(x*=-1 && sum!=n){
        int r=2*n-1;
        int l=1;
        if(x==-1){
            if(!s.count(l)){
                s.insert(l);
                sum++;
                s.insert(l+last);
                last=l;
            }
            l++;
        }else {
            if(!s.count(r)){
                s.insert(r);
                s.insert(r+last);
                last=r;
            }
            r--;
        }
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