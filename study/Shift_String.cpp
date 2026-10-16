#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
ll kmp(const string& x,ll m,const string& y,ll n,ll next[]){// x是模式串，y是珠串；
    //ll next[]是next数组指向第一个next第一个位置的指针
    ll i,j;
    ll ans=0;
    
}
void kmp_pre(const string &x,ll m,ll next[]){
    ll i,j;
    j=next[0]=-1;
    i=0;
    while(i<m){
        while(-1!=j && x[i]!=x[j]){
            j=next[j];
        }
        next[++i]=++j;
    }
}
void solve() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    s1+=s1;
    ll n=s2.length();

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