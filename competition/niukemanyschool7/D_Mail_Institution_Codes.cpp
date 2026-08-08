#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    ll n;
    cin >>n;
    ll p[n]={0};
    string s;
    getline(cin,s);
    s="";
    vector<vector<string>> a(n);
    for(ll i=0;i<n;i++){
        string line;
        getline(cin,line);
        stringstream ss(line);
        string word;
        while(ss >> word){
            a[i].push_back(word);
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i==j)continue;
            if(a[i].size()==a[j].size()){
                string s1;
                string s2;
                for(ll k=0;k<a[i].size();k++){
                    s1+=a[i][k][0];s2+=a[j][k][0];
                }
                if(s1==s2){
                    for(ll k=0;k<a[i].size();k++){
                        if(a[i][k]!=a[j][k]){
                            p[i]=max(p[i],k);
                            p[j]=max(p[j],k);
                            break;
                        }    
                    }            
                }
            }
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<=p[i];j++){
            cout << a[i][j];
        }
        for(ll j=p[i]+1;j<a[i].size();j++){
            cout << a[i][j][0];
        }
        cout << endl;
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