#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int n,used[1000],arr[1000];
void print(){
    for(int i=1;i<=n;i++){
        cout << "    " << arr[i];
    }
    cout << endl;
}
void dfs(int k){
    if(k==n){
        print();
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=1;
            arr[k+1]=i;
            dfs(k+1);
            used[i]=0;
        }
    }
}
void solve() {
    cin >> n;
    dfs(0);
    return;
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