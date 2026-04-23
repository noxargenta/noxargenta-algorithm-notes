#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s= " " + s;
    vector<array<int,2>> pre(n+1),suf(n+1);
    for(int i=2;i<=n;i++){
        pre[i][0]=pre[i-1][0];
        pre[i][1]=pre[i-1][1];
        pre[i][s[i-1]-'a']++;
    }
    for(int i=n-1;i!=0;i--){
		suf[i][0]=suf[i+1][0];
		suf[i][1]=suf[i+1][1];
		suf[i][s[i+1]-'a']++;
	}
    i64 ans=1e18,cnt=0;

    for(int i=1;i<=n;i++){
        if(s[i]=='a') cnt+=pre[i][1];
    }
    ans=min(ans,cnt);
    

    cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='b') cnt+=pre[i][0];
    }
    ans=min(ans,cnt);
    
    cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='a') cnt+=min(pre[i][1],suf[i][1]);
    }
    ans=min(ans,cnt);
    
    cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='b') cnt+=min(pre[i][0],suf[i][0]);
    }
    ans=min(ans,cnt);
    
    cout<<ans<<"\n";
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
