#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    string s;
    cin >>s;
    s="0"+s;
    vector<int> a(n+1,0);
    vector<int> b;//下标
    vector<bool> del(n+1,0);
    vector<int> pre(n+1,0);
    int sum=0;
    int last=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        sum+=a[i];
        pre[i]=pre[i-1]+a[i];
        if(s[i]=='c'){
            s[i]='b';
        }
        if(a[i]<0){
            b.push_back(i);
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