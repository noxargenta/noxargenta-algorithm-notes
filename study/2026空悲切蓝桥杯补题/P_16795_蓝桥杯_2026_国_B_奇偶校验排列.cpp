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
    vector<int> cnt(100000+1,0);
    vector<int> pre(100000+1,0);
    for(int i=0;i<n;i++) {
        if(s[i]-'0'==0){
            zero++;
        }else {
            int nowz=(zero+1)*zero/2;
            cnt[0]+=nowz;
            int ways=zero +1;
            zero=0;
            int val=0;
            for(int j=i;j<n && j<i+6;j++){
                val= val * 10 + (s[j]-'0');
                if(val>100000){
                    break;
                }
                cnt[val]+=ways;
            }
        }
    }
    cnt[0] += zero * (zero + 1) / 2;
    pre[0] = cnt[0];
    for(int i=1;i<=100000;i++){
        pre[i]=pre[i-1] + cnt[i];
    }
    while(m--){
        int l,r;
        cin >> l >> r;
        if(l==0){
            cout << pre[r] << endl;
        }else {
            cout << pre[r]-pre[l-1] << endl;
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