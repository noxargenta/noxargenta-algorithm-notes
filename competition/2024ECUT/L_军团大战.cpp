#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int fa[200009];
int find(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=find(fa[x]);
}
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    vector<int> sum(n+1,0);
    //vector<in t> a(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        int finx=find(x);
        fa[i]=finx;
        
        sum[finx]++;
    }
    int my=0;
    vector<int> b;
    for(int i=2;i<=n;i++){
        if(sum[i]!=0){
            b.push_back(sum[i]);
        }
    }
    my=sum[1];
    bool ok=1;
    sort(b.begin(),b.end());
    for(int i=0;i<=b.size()-1;i++){
        if(my>b[i]){
            my+=b[i];
            continue;
        }else {
            ok=0;
        }

    }
    if(ok){
        cout << "YES\n"; 
    }else  {
        cout << "NO\n";
    }
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