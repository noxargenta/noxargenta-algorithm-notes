#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
bool ok=0;
#define ll long long
ll kmp(const string& x,ll m,const string& y,ll n,ll next[]){// x是模式串，y是主串；
    //ll next[]是next数组指向第一个next第一个位置的指针
    ll i,j;
    ll ans=0;
    i=j=0;
    while(i<n){
        while(-1!=j && y[i]!=x[j]){
            j=next[j];
        }
        i++;
        j++;
        if(j>=m){
            ans++;
            j=next[j];
        }
        if(ans>=1){
            ok=1;
            return (ll)i;  
        }

    }
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
    ll m=s2.length();
    ll n=s1.length();
    
    vector<ll> next(m);
    
    kmp_pre(s2,m,next.data());
    ll ans=kmp(s2,m,s1,n,next.data());
    if(!ok){
        cout << -1 <<endl;

    }else {
        cout << ans <<endl;
    }
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