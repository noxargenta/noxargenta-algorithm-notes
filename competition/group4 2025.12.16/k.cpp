#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    string s;
    cin >> n>>s;//0--(n-1)
    bool ok=1;
    vector<int> a(n+2,0);
    a[0]=1;a[n+1]=1;
    for(int i=0;i<n;i++){
        if(s[i]=='W'){
            a[i+1]=1;
        }
    }
    for(int l=0,r=1;l<n+1 && r<n+2;){
        while(a[r]!=1){
            r++;
        }
        int B=0,R=0;
        for(int j=l;j<r && j<n;j++){
            if(s[j]=='B'){
                B++;
            }else if(s[j]=='R'){
                R++;
            }
        }
        if(B!=0 && R==0 || B==0 && R!=0){
            ok=0;
            break;
        }
        l=r;
        r++;
    }
    if(ok){
        cout << "YES\n";
    }else {
        cout << "NO\n";
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