#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {-
    int n,q;
    cin >> n >> q;
    vector<int> a(2005,0);
    int ans=0;
    int ans1=0;
    for(int i=1;i<=n;i++){
        int x;
        cin >>x;
        a[x]++;
        ans1+=x;
    }
    
    vector<int> b(2005,0);
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        
        if(x==1 || ans1==0){
            cout << ans1 << endl;
            continue;
        }
        fill(b.begin(),b.end(),0);
        ans=0;
        for(int j=1;j<=2000;j++){
            
            if(a[j]==0)continue;
            ans+=a[j]*(j/x);
            // a[j/x]+=a[j];
            b[j/x]+=a[j];
        }
        a=b;
        cout << ans << endl;
        ans1=ans;
        
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