#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    char x;
    int b=0;
    int a[101];
    for(int i=1;i<=100;i++){
        cin >> x;
        a[i]=x-'0';
    }
    for(int i=1;i<=100;i++){
        if(a[i]==0){
            b=3-b;
        }else if(a[i]==1){
            if(b==1 || b==3){
                b=4-b;
            }
        }else if(a[i]==2){
            b=b^1;
        }else if(a[i]==3){
            if(b==0 || b==2){
                b=2-b;
            }
        }else if(a[i]==5){
            if(b==0){
                b=3;
            }else {
                b--;
            }
        }else if(a[i]==4){
            if(b==3){
                b=0;
            }else {
                b++;
            }
        }
        cout << b;
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