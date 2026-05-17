#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int ge=0;
int x,y,z;
vector<int> a(10,0);
void cf(int x){
    while(x!=0){
        ge=x%10;
        x=x/10;
        a[ge]++;
    }
}
void solve() {
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            for(int k=1;k<=9;k++){
                
                x=i+j*10+k*100;
                y=2*x;
                z=3*x;
                cf(x);
                cf(y);
                cf(z);
                bool ok=1;
                for(int i=1;i<=9;i++){
                    if(a[i]!=1){
                        ok=0;
                    }
                }
                if(ok){
                    cout << x << ' ' << y << ' ' << z << endl;
                }
            }
        }
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