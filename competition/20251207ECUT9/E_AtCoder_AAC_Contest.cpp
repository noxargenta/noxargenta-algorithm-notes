////AAC ABC ACC    
////A2C1 C2A1 A1B1BC1
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int a,b,c;
    cin >> a >>b >> c;
    int sum=0;
    if(a<c){
        swap(a,c);
    }
    while((a>=2&&c>=1)||(a>=1&&b>=1&&c>=1)||(c>=2&&a>=1)){
        if(b>=1){
            a--,b--,c--;
            sum++;
            continue;
        }
        if(a<c){
        swap(a,c);
        }
        if(b==0){
        a-=2;
        c--;
        sum++;
        }
    }
    cout << sum << endl;
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