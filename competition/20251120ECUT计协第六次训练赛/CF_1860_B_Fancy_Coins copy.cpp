#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int m,k,a1,ak;
    cin >> m>>k>>a1>>ak;
    int take_1=m%k;
    int take_k=m/k;
    int fan1=max((int) 0,take_1-a1);
    int drop1=max((int)0,a1-take_1 );
    int fank=max((int)0,take_k-ak);
    int dropk=max((int)0,ak-take_k);
    int re=min(drop1/k,fank);
    cout<< fan1+fank-re << endl;
;}
#undef int 
int main(){
    int _=1;
    cin >> _;
    while(_--){
        solve();
    }
    return 0;
}
