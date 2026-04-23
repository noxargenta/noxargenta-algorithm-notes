#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int minn=1000000009;
	int x,y,a,b,c,d;
    cin>>x>>y>>a>>b>>c>>d;
    if(x==y){
        cout<<0<<endl;
        return;
    }
    if(((x&a)|b)==y||((x|b)&a)==y){
        minn=c+d;
    }
    if((x&a)==y){
        minn=min(minn,c);
    }
    if((x|b)==y){
        minn=min(minn,d);
    }
    if(minn==1000000009){
        cout<<-1<<endl;
        return;
    }
    cout<<minn<<endl;
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