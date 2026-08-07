#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >> n;
    getchar();
    string s;
    vector<vector<string>> a(n);
    
    for(int i=0;i<n;i++){
        string w="";    
        getline(cin,s);
        for(char c:s){
            if(c==' ' || c=='/n'){
                if(w!=""){
                    a[i].push_back(w);
                }
            }
        }
    }   
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}