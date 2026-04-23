#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int val=1;
    int cnt5=0,cnt2=0;
    for(int i=1;i<=n;i  ++){
        
        int x;
        cin >> x;
        while(x>0 && x%2==0){
            cnt2++;
            x/=2;
        }
        while(x>0 && x%5==0){
            cnt5++;
            x/=5;
        }
        val=(val*(x%10))%10;
    }
    if(cnt5>cnt2){
        val=5;
    }else {
        for(int i=1;i<=cnt2-cnt5;i++){
            val=(val*2)%10;
        }
    }
    cout << val << endl;
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