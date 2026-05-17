#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
vector<int> a(10,2021);
int cf(int x){
    int ge=0;
    while(x!=0){
        ge=x%10;
        x/=10;
        a[ge]--;
    }
}
void solve(){
    for(int i=1;;i++){
        cf(i);
        
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