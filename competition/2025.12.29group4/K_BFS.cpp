#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<int> fu={1};//第0层节点数是1;    
    int cur=0;//下一层的节点数;
    for(int l=2,r=3;l<=n;l=r,r++){
        while(r<=n && a[r]>a[r-1]){
            r++;
        }
        cur+=r-l;
        fu.back()--;
        if(!fu.back()){
            fu.push_back(cur);
            cur=0;
        }
    }
    cout << fu.size() -(cur==0)<<endl;
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