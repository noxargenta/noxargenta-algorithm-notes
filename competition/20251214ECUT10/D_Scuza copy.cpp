#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int n,q;    
vector<int> a(200009),b(200009);
void solve() {
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int x;
        cin >>x;
        a[i]=max(a[i-1],x);
        b[i]=b[i-1]+x;
    }
    while(q--){
        int x;
        cin >> x;
        int l=0,r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(a[mid]>x){
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
        cout << b[l-1] << ' ';
    }
    cout << endl;
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