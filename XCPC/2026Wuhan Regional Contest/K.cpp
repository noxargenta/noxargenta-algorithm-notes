// https://qoj.ac/contest/4616/problem/23666
/*
2
4
1 1 2
5 3 4 2
7 6 5 4
8
1 1 1 2 5 5 3
6 4 3 5 4 3 4 2
9 5 7 7 2 1 1 5
*/

/*

4
1680

*/

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
#define ull unsigned long long
void solve() {
    ll n;
    cin >> n;
    
    vector<ll> f(n+1,0);
    f[1]=1;
    for(ll i=2;i<=n;i++){
        cin >> f[i];
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