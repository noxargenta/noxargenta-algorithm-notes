#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
    int n;
    cin >> n ;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    stack<int> s;
    vector<int> left(n+1,0),right(n+1,n+1);
    for(int i=1;i<=n;i++){
        while(!s.empty() && a[s.top()]>=a[i]) s.pop();
        if(!s.empty()) left[i]=s.top();
        s.push(i);
    }
    while(!s.empty()){
        s.pop();
    }
    for(int i=n;i>=1;i--){
        while(!s.empty() && a[s.top()] > a[i]){
            s.pop();
        }
        if(!s.empty()) {
            right[i]=s.top();
        }else {
            right[i]=n+1;
        }
        s.push(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=a[i] * (i-left[i]) * (right[i]-i);
    }
    cout << ans << endl;
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