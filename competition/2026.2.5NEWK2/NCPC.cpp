#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    map<int,int> win;
    map<int,int,greater<int>> co;
    bool ok=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        co[a[i]]++;
    }
    for(auto i=co.begin();i!=co.end();i++){
        int x=i->first;
        int y=i->second;
        if(ok==1 && y%2==0){
            win[x]=1;
        }
        if(y%2!=0){
            win[x]=1;
            if(ok!=1){
                break;
            }
        }else {
            ok=1;
            if(win[x]!=1){
                win[x]=0;
            }
        }
    }
    string s="";
    for(int i=1;i<=n;i++){
        if(win[a[i]]==1){
            s+='1';
        }else {
            s+='0';
        }
    }

    cout << s << endl;
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