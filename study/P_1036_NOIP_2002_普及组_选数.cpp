#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
vector<int> a(30);
int n,cnt,kk;
const int N=100000008;
bitset<N> c;
int b[200];

//int vis[200];
bool isPrime(int x){
    if(x<2){
        return 0;
    }else {
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                return 0;
            }
        }
    }
    return 1;
}
void dfs(int k,int u,int sum){
    if(kk-(k-1) > n-u +1){
        return;
    }
    if(k-1==kk){
        // for(int i=1;i<=kk;i++){
        //     sum+=b[i];
        // }
        if(c[sum]){
            cnt++;
        }
        return;
    }
    for(int i=u;i<=n;i++){
        //if(vis[i]==0){
            //vis[i]=1;
            //b[k]=a[i];
            dfs(k+1,i+1,sum+a[i]);
        //}
    }
};

void solve() {
    
    cin >> n;
    cin >> kk;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    dfs(1,1,0);
    
    cout << cnt << endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    c.set();
    c[0] = c[1] = 0;
    
    vector<int> primes;
    for(int i=2;i<N;i++){
        if(c[i]){
            primes.push_back(i);
        }
        for(auto x : primes){
            if(x * i>=N)break;
            c[x * i]=0;
            if(i % x==0)break;
        }
    }
    
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}