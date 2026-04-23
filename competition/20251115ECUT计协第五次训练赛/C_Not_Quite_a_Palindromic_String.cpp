#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n;
    int k;
    cin >> n >> k;
    string s;
    cin >> s;/////n%2==0;///2<= 2i <n+1 
    int x1=0,x0=0;
    for(int i=0;i<n;i++){
        if(s[i]-'0'==1){
            x1++;
        }else {
            x0++;
        }
    }
    int xmax=max(x1,x0);
    int xmin=min(x1,x0);
    n=((xmax-xmin)/2);
    x1=xmax;
    x0=xmin;
    //;
    int maxn=x1/2+x0/2;
    if(k<=maxn){
        if(xmax-k*2==xmin){
            cout << "YES\n";
        }else if((k-n)%2==0 && xmax-n*2==xmin && k>=n &&k<=maxn){
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }else   {
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