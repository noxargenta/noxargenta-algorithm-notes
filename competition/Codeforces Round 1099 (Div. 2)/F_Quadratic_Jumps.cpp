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
    vector<int> a;
    a.push_back(last);
    int r=2*n-1;
    int l=1;
    while(sum!=n){
        x*=-1;
        if(x==-1){
            if(!s.count(l) && !s.count(r+last)){
                s.insert(l);
                a.push_back(l);
                sum++;
                s.insert(l+last);
                last=l;
            }
            l++;
        }else {
            if(!s.count(r) && !s.count(r+last)){
                s.insert(r);
                a.push_back(r);
                s.insert(r+last);
                sum++;
                last=r;
            }
            r--;
        }
    }
    for(auto x : a){
        cout << x  << ' ';
    }
    cout << endl;
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