#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int m,k,a1,ak;
    cin >> m >> k>>a1>>ak;
    if(m<=a1 || (m>a1 && (m-a1)%k==0 && (m-a1)/k<=ak)){
        cout << "0\n";
    }else if(m>a1&&(m-a1)%k!=0&&(m-a1)/k<=ak){
        cout << (m-a1)%k<<endl;
    }else if(m>a1+ak*k){
        cout << (m-a1-k*ak)%k+(m-a1-k*ak)/k<<endl;
    }

}
#undef int 
int main(){
    int _=1;
    cin >> _;
    while(_--){
        solve();
    }
    return 0;
}
