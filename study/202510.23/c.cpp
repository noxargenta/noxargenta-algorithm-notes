#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct xy{
    int x;
    int y;
};
void solve() {
    int x,y;
    cin >>x >> y ;
    vector<xy> xy(5);
    vector<string> a(x);
    for(int i=0;i<x;i++){
        cin >> a[i];
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            char t=a[i][j];
            if(t=='s'){
                xy[0].x=i;
                xy[0].y=j;
            }else if(t=='n'){
                xy[1].x=i;
                xy[1].y=j;
            }else if(t=='u'){
                xy[2].x=i;
                xy[2].y=j;
            }else if(t=='k'){
                xy[3].x=i;
                xy[3].y=j;
            }else if(t=='e'){
                xy[4].x=i;
                xy[4].y=j;
            }
        }
    }
    for(int i=0;i<5;i++){
        cout << xy[i].x+1 << " " << xy[i].y+1 << endl;
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