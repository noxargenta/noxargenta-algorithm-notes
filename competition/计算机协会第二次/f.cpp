#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct din
{
    int h;
    int l;
    bool ok;
};

void solve() {
    int n;
    cin >> n;
    vector<din> ding(n);
    int num=0;
    for(int i=0;i<n;i++){
        cin >> ding[i].h >> ding[i].l; 
        if(ding[i].l>=ding[i].h){
            ding[i].ok=true;
        }else {
            ding[i].ok=false;
            num ++;
            }
    }
    cout << num << endl;
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