#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+2,0);
    vector<int> l(n+2),r(n+2);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        l[i]=a[i]+l[i-1];
    }
    for(int i=n;i>=1;i--){
        r[i]=a[i]+r[i+1];
    }
    int sum=0;
    int sa=0,sb=0;
    int lx=1,rx=n;
    int te=a[1];
    sa+=te;
    sum++;
    lx++;//lx=2
    int turn=1;
    while(lx<=rx && l[rx]-l[lx-1]>te){
        
        turn*=-1;
        //cout <<"turn" <<turn << endl;///////
        sum++;
        //cout <<"sum" <<sum << endl ;////
        if(turn==-1){
            for(int i=rx;i>=lx;i--){
                if(r[i]-r[rx+1]>te){
                    sb+=r[i]-r[rx+1];
                    //cout << "sb"<<sb<<endl;////
                    te=r[i]-r[rx+1];
                    rx=i-1;
                    
                    //cout << "te"<<te <<endl;//
                    break;
                }
            }
            
        }else {
            for(int i=lx;i<=rx;i++){
                if(l[i]-l[lx-1]>te){
                    sa+=l[i]-l[lx-1];
                    te=l[i]-l[lx-1];
                    lx=i+1;
                    
                    //cout << "te"<<te <<endl;//
                    //cout << "sa"<<sa<<endl;////
                    break;
                }
            }
            
        }
    }
    //cout << rx-lx << endl;
    turn*=-1;
    if(lx-rx==1){
        cout << sum <<" "<<sa<<" "<<sb<<endl;
    }else if(turn==-1){
        cout << sum+1 <<" "<<sa<<" "<<sb+l[rx]-l[lx-1]<<endl;
    }else {
        cout << sum+1 <<" "<<sa+l[rx]-l[lx-1]<<" "<<sb<<endl;
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