#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,k,q;
    cin >> n>> k>>q;
    vector<int> a(200);
    vector<int> c(q+1),l(q+1),r(q+1);
    vector<int> d1(105),d2(105);
    for(int i=1;i<=q;i++){
        cin >> c[i] >> l[i] >>r[i];
        if(c[i]==1){
            d1[l[i]]++;
            d1[r[i]+1]--;
        }else {
            d2[l[i]]++;
            d2[r[i]+1]--;
        }
    }
    int cur=0;
    for(int i=1;i<=n;i++){
        d1[i] += d1[i-1];
        d2[i]+=d2[i-1];
        if(d1[i]!=0){
            if(d2[i]!=0){
                a[i]=k+1;
            }else{
                a[i]=k;
            }
        }else {
            a[i] =cur;
            cur=(cur+1)%k;
        }
        cout << a[i]<<' ';
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