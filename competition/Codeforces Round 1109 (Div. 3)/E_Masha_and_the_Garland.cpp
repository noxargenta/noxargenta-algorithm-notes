#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,q,l,r,k;
    string s="0";
    string tem;
    cin >> n >> q>> tem;
    s+=tem;
    vector<int> pre(n+3,0);///10010
    pre[1]=0;
    for(int i=1;i<n;i++){
        if(s[i]==s[i+1]){
            pre[i+1]++;
            pre[i+1]+=pre[i];
        }
    }
    while(q--){
        cin >> l,r,k;
        if(l==r) {
            cout << "YES\n";
            continue;
        }
        int cha=pre[r]-pre[l];
        if((cha+1)/2<=k){
            
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