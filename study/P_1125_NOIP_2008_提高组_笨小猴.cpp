#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int isPrime(int x){
    if(x<2){
        return 0;
    }
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                return 0;
            }
        }
    return 1;
}
void solve() {
    vector<int> a(26,0);
    string s;
    cin >> s;
    int maxn=0;
    int minn=10000;
    for(int i=1;i<s.length();i++){
        int x=++a[s[i]-'a'];
        minn=min(minn,x);
        maxn=max(maxn,x);
    }
    if(isPrime(maxn-minn)){
        cout  << "Lucky Word\n";
        cout << maxn-minn << endl;
    }else {
        cout << "No Answer\n0";
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