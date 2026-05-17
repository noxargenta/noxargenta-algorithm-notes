#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
vector<int> a(10,2021);
int ok=0;
void cf(int x){
    int ge=0;
    while(x!=0){
        ge=x%10;
        
        if(a[ge]==0){
            ok=1;
            break;
        }
        a[ge]--;
        x/=10;
        
    }
}
void solve(){
    for(int i=1;;i++){
        cf(i);
        if(ok==1){
            cout << i-1 << endl;
            break;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    //cin >> _;
    while(_--){
        solve();
    }
}