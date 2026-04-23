#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int ce(int x,int y){
    int n2=0;
    for(;x!=1;n2++){
        x=ceil(x/y);
    }
    return n2;
}
int sq(int n){
    int m2=2;
    int i=1;
    for(;m2<n;){
        m2*=2;
        i++;
    }
    return i-1;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    if(n==3){
        cout << "2\n"<<"3 2\n"<<"3 2\n";
    }else{
        for(int i=0;i<=n;i++){
            a[i]=i;
        }
        int nn1=sq(n)/2;
        int x6=0;
        if(nn1==2){
            x6=0;
        }else{
            x6=ce(nn1,2.0);
        }
        int x7=ceil(n/nn1);
        cout << n-3+ x6+ 1+ce(x7,2.0)<<endl;
        for(int i=3;i<nn1;i++){/////
            cout << i << " " << i+1 << endl;
        }
        for(int i=nn1+1;i<n;i++){/////
            cout << i << " " << i+1 << endl;
        }
        cout << n <<" "<< nn1 <<endl;
        int tempn=n;
        tempn=ceil(n/nn1);
        for(int i=0;i<ce(tempn,2.0);i++){
            cout << n <<" "<< 2 <<endl;
        }
        if(nn1>2){
            for(int i=0;i<ce(nn1,2.0);i++){
                cout << nn1 << " " << 2 <<endl;
            }
        }
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