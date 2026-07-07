#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int zero=0;
    vector<int> cnt(n+1,0);
    vector<int> pre(n+1,0);
    for(int i=0;i<n;i++) {
        if(s[i]-'0'==0){
            zero++;
        }else {
            int nowz=(zero+1)*zero/2;
            cnt[0]+=nowz;
            int ways=zero +1;
            zero=0;
            for(int j=i;j<n && j<i+6;j++)
        }
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