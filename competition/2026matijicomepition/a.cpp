#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF=0x3f3f3f3f;
const int INFLL=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;
    cin >> n;
    int maxy=0;
    int maxx=0;
    int minx=INF,miny=INF;
    for(int i=1;i<=n;i++){
        int x,y;
        cin >> x >> y;
        maxx=max(maxx,x);
        maxy=max(maxy,y);
        minx=min(minx,x);
        miny=min(miny,y);
    }
    cout << (maxy-miny)*(maxx-minx) << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    //cin >> _;
    while(_--){
        solve();
    }
}