#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;    
    vector<int> p(n+1,0);
    int minp=0;
    for(int i=0;i<n;i++){
        p[i+1]=p[i]+(s[i]=='(' ? 1:-1);
        minp=min(minp,p[i+1]);
    }
    int pot=-1;
    for(int i=0;i<=n;i++){
        if(p[i]==minp){
            pot=i;
            break;
        }
    }
    vector<int> allow;
    for(int i=0;i<pot;i++){
        if(s[i]=='('){
            allow.push_back(i);
        }
    }
    for(int i=pot;i<n;i++){
        if(s[i]==')'){
            allow.push_back(i);
        }
    }
    string ans(n,'0');
    int nn=min(k,(int)allow.size());
    for(int i=0;i<nn;i++){
        ans[allow[i]]='1';
    }
    cout << ans  << endl;
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