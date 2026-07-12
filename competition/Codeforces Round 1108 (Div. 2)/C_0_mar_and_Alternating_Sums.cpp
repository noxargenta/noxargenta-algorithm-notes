#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
const int mod=1e9+7;
int ksm(int x,int n){
    int ans=1;
    x%=mod;
    while(n>0){
        if(n%2==1){
            ans=ans*x%mod;
        }
        ans=ans*ans%mod;
        n/=2;
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    int m=0;//-1num;
    vector<pair<int ,int>> cnt;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x==-1){
            m++;
        }else {
            if(cnt.empty() || )
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