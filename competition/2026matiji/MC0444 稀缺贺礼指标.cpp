#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int a[n+1];
    int minn=1000000000+9;
    int maxx=-99999999;
    set<int> s;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        //cout <<"min:" <<minn << endl;
        minn=min(minn,a[i]);
        //cout <<"min:" <<minn << endl;
        maxx=max(maxx,a[i]);
        s.insert(a[i]);
    }
    //cout <<"min:" <<minn << endl;
    if(minn>0){
        cout << 0 << endl;
    }else {
        for(int i=1;i<=maxx+1;i++){
            if(!s.count(i)){
                cout << i << endl; 
            }
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