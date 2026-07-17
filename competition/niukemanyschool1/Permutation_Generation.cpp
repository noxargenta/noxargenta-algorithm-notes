#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long

int sum(vector<int> x,int mod){
    int summ=0;
    for(int i=0;i<x.size();i++){
        summ+=x[i]*(2*i+1)%mod;
    }
    return summ;
}
void solve() {
    int n,k,x;
    cin >> n  >> k >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int f1=sum(a,n);
    
    if(sum(a,n)==n){
        for(auto x : a){
            cout << x << " ";
        }
        cout << endl;
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