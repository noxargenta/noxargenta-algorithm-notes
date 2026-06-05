#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
bitset<N> c;
c.set();
c[0]=c[1]=0;
vector<int> prime;
for(int i=2;i<N;i++){
    if(c[i]==1){
        prime.push_back(c[i]);
    }else{
        for(auto x : prime){
            if(x*i>=N)break;
            c[x*i]=0;
            if(i%x==0)break;
        }
    }
}
int find(int x){
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}
void solve() {
    
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}