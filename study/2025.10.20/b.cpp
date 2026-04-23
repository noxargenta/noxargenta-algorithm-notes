#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int s[3][3]={{7,8,9},{4,5,6},{1,2,3}};
    int a,b;
    cin >> a >> b;
    int xa,xb,yb;
    int ya;
    bool found=0;
    for (int r=0;r<3;r++){
        for(int l=0;l<3;l++){
            if(s[r][l]==a){
                xa=l;
                ya=r;
                found=1;
                break;
            }
        }
        if(found==1){
            found=0;
            break;
        }
    }
    for (int r=0;r<3;r++){
        for(int l=0;l<3;l++){
            if(s[r][l]==b){
                xb=l;
                yb=r;
                found=1;
                break;
            }
        }
        if(found==1){
            break;
        }
    }
    if (ya == yb && abs(xa - xb) == 1){
        cout << "Yes";
    } else cout << "No";
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