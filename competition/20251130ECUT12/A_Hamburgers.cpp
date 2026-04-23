#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    string str;
    cin >> str;
    int ans=0;
    int b,s,c;///num;
    cin >> b  >> s >> c;
    int B,S,C;
    cin >> B >> S  >> C;
    int count ;
    cin >> count;
    int bx=0,sx=0,cx=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='B'){
            bx++;
        }else if(str[i]=='S'){
            sx++;
        }else {
            cx++;
        }
    }
    int l=0,r=2000000000005;
    while(l<=r){
        int mid=(l+r)/2;
        int nb=max((int)0,mid*bx-b);
        int ns=max((int)0,mid*sx-s);
        int nc=max((int)0,mid*cx-c);
        int sum=nb*B+S*ns+nc*C;
        if(sum>count){
            r=mid-1;
        }else{
            l=mid+1;
            ans=mid;
        }
    }
    cout << ans << endl;
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