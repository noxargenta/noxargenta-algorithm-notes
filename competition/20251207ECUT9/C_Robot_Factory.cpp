#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m ,k;
    cin >> n >> m >> k;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> b[i];
    }
    sort(a.begin()+1,a.end(),greater()  );
    sort(b.begin()+1,b.end(),greater()  );
    int i=1,j=1;
    int maxx=0;///???k
    while(i<=n && j<=m  ){
        if(a[i]<=b[j]){
            i++;
            j++;
            maxx++;
        }else {
            i++;
        }
    }
    if(maxx>=k){
        cout << "Yes\n";
    }else{
        cout << "No";
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