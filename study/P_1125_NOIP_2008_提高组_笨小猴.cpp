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
    for(int i=0;i<s.length();i++){
        int x=++a[s[i]-'a'];
    }
    for(auto x : a){
        if(x==0){
            continue;
            //遍历数组的时候注意一下最小值和初始值，初始值是
            //0那么最小值遍历一遍的话就一定是0，所以会导致出错
        }
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