#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    bool ok=0;
    map<string,int> a;
    for(int i=0;i<n;i++){
        string x;
        cin >> x;
        a[x]++;
    }
    int m;
    cin >> m;
    int num=0;
    int res=100005;
    set<string> c,b;
    for(int i=0;i<m;i++){
        string x;
        cin >> x;
        if(a.count(x) && !b.count(x)){
            num++;
            b.insert(x);
            c.insert(x);
        }else if(a.count(x)&& b.count(x)){
            continue;
        }else if(!a.count(x)&& !b.count(x)&&num>=1){
            res=min(num,res);
            num=0;
            ok=1;
            b.clear();
        }
    }
    if(num>=1){
        res=min(num,res);
        num=0;
        ok=1;
    }
    cout << c.size()<< endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while(_--) {
        solve();
    }
    return 0;
}