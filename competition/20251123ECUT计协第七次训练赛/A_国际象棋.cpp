#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int num=0;
    int ji=0;
    for(int i=0;i<8;i++){
        string t;
        cin >> t;
        for(int j=0;j<8;j++){
            if(t[j]=='#'){
                num++;
            }
        }
        if(num==2){
            ji=i;
            break;
        }
        num=0;
    }
    int x;
    int y;
    
    for(int i=ji+1;i<8;i++){
        string t;
        cin >> t;
        int j=0;
        num=0;
        int temp=0;
        for(;j<8;j++){
            if(t[j]=='#'){
                num++;
                if(num==1){
                    temp=j;
                }
            }
        }
        if(num==1){
            x=i+1;
            y=temp+1;
            ji=i;
            break;
        }
    }
    for(int i=ji+1;i<8;i++){
        string t;
        cin >> t;
    }
    cout << x <<" " <<y<< endl;
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