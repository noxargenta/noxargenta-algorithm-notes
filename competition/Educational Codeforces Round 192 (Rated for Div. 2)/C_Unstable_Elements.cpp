#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1);
    map<int,int> mp1;//i的出现次数
    map<int,int> mp2;//出现i次的数字的个数
    for(int i=1;i<=n;i++){
        cin >> a[i];
        mp1[a[i]]++;
    }
    for(auto x:mp1){
        mp2[x.second]++;
    }
    int ans=0;
    int len=n;
    int dif=mp1.size();
    int del=0;
    for(auto x:mp2){
        int count=x.first;
        int num=x.second;
        if(abs(len-k)%dif==0 && (x.first-del)>((len-k)/dif)){
            ans++;
        }
        len-=(x.first-del)*dif;
        dif-=x.second;
        del=x.first;
    }
    cout << ans <<endl;
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