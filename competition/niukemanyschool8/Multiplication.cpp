#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll a,b,c;cin >>a >> b >> c;
    if(c<a){
        string x=string(c,'9');
        string y=string(b,'9');
        string x1=x+string(a-c+b,'0') + string(a,'9');
        string x2=x+string(a-c+a+b,'0');
        string y1=y+string(b,'9');
        string y2=y+string(b,'0');
        cout << x1<<" "<<y1<<" "<< x2 << " " << y2 <<endl;
    }else if(c<b){
        string y=string(c,'9');
        string x=string(a,'9');
        string y1=y+string(b-c+a,'0') + string(b,'9');
        string y2=y+string(b-c+b+a,'0');
        string x1=x+string(a,'9');
        string x2=x+string(a,'0');
        cout << x1<<" "<<y1<<" "<< x2 << " " << y2 <<endl;
    }else {
        string x=string(a,'9');
        string y=string(b,'9');
        string x1=x+string(c-a+b,'9') + string(a,'9');
        string x2=x+string(c-a+b,'0')+string(a,'0');
        string y1=y+string(c-b+a,'9')+string(b,'9');
        string y2=y+string(c-b+a,'0')+string(b,'0');
        cout << x1<<" "<<y1<<" "<< x2 << " " << y2 <<endl;
    }

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