#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct person{
    int id;
    i64 a;
    i64 b;
};
void solve() {
    int n;
    cin >> n;
    vector<person> p(n);
    for(int i=0;i<n;i++){
        p[i].id=i+1;
        cin >> p[i].a >> p[i].b;
    }
    sort(p.begin(),p.end(),[](person& p1,person& p2){
        i64 v1=p1.a*(p2.a+p2.b);
        i64 v2=p2.a*(p1.a+p1.b);
            if(v1!=v2){
                return v1>v2;
            }
            return p1.id<p2.id;
        }
    );
    for(int i=0;i<n;i++){
        cout << p[i].id << " ";
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