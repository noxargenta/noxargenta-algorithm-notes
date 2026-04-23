#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
struct pp{
    int day;
    int c;
};
bool vs(pp x,pp y){
    return x.c>y.c;
}
void solve() {
    int n;
    cin >> n;
    vector<pp> a(n),b(n),c(n);
    for(int i=0;i<n;i++){cin >> a[i].c;
        a[i].day=i;
    }
    for(int i=0;i<n;i++){cin >> b[i].c;
        b[i].day=i;
    }
    for(int i=0;i<n;i++){cin >> c[i].c;
        c[i].day=i;
    }
    sort(a.begin(),a.end(),vs);
    sort(b.begin(),b.end(),vs);
    sort(c.begin(),c.end(),vs);
    int ans=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(a[i].day!=b[j].day&& b[j].day!=c[k].day && c[k].day!=a[i].day){
                    ans=max(ans,a[i].c+b[j].c+c[k].c);
                }
            }
        }
    }
    cout << ans << endl;
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