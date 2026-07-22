#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
void solve(){
    int n,m;
    cin >> n>> m;
    vector<int>a(n+1);
    vector<int>num(m+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        num[a[i]]++;
    }
    int ans =0;
    for(int i=n;i>=1;i--){
        if(num[a[i]]>1){
            ans++;
            num[a[i]]--;
        }else {
            break;
        }
    }
    cout << ans << endl;
}
int main(){
    int _=1;
    cin >> _;
    while(_--){
        solve();
    }
    return 0;
}