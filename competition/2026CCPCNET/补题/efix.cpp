#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> a(3,vector<int>(n+1));
    vector<vector<int>> pos(3,vector<int>(n+1));
    for(int i=0;i<3;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            pos[i][a[i][j]]=j;
        }
    }
    vector<int> ok(n+1,0);
    auto check=[&](int x,int y){
        int mx=0;

        for(int k=1;k<n;k++){
            mx=max(mx,pos[y][a[x][k]]);

            if(mx==k){
                ok[k]=1;
            }
        }
    };

    check(0,1);
    check(0,2);
    check(1,2);

    int ans=1;

    for(int k=1;k<n;k++){
        ans+=ok[k];
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll _=1;
    cin >> _;

    while(_--){
        solve();
    }
}