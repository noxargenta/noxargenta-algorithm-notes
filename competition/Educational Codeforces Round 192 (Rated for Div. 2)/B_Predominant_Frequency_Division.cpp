#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<int> p1(n+1);
    vector<int> p2(n+1);
    int cp1,cp2;
    for(int i=1;i<=n;i++){
        int x=a[i];
        if(x==1){
            cp1++;
            cp2++;
        }else if(x==2){
            cp1--;
            cp2++;
        }else{
            cp1--;
            cp2--;
        }
        p1[i]=cp1;
        p2[i]=cp2;
    }
    int maxjj=-999999999;
    for(int i=n-2;i>=0;i--){
        int j=i+1;
        maxjj=max(maxjj,p2[j]);
        if(p1[i]>=0 || maxjj-p2[j]>=0){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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