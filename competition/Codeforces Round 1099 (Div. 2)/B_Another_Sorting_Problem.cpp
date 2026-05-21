#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin  >> n;
    vector<int> a(n+2,0);
    a[n+1]=1000000001;
    vector<bool> b(n+2,0);
    vector<int> c(n+2,0);
    int last=a[1];
    for(int i=1;i<=n;i++){
        cin  >> a[i];
        if(i>1){
            if( a[i]<last){
                b[i]=1;
            }
            last=max(last,a[i]);
        }
    }
    last=-1;
    for(int i=1;i<=n;i++){
        if(last==-1 && b[i]==1){
            last=a[i];
        }
        if(b[i]==1){
            if(a[i]<last){
                cout << "NO\n";
                return;
            }
            last=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        c[i]+=c[i-1]+b[i];
    }
    for(int i=1;i<=n;i++){
        if(b[i]==1){
            int l=i,r=i;
            while(b[l]!=0){
                l--;
            }
            while(b[r]!=0){
                r++;
            }
            if(r!=n+1){
                i=r+1;
            }
            if((c[r]-c[l])<=(a[r]-a[l]+1)){
                continue;
            }else {
                cout << "NO\n";
            }
        }
    }
    cout << "YES\n";
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