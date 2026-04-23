#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n); 
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i]=a[i];
    }
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            for(int  j=i+1;j< n;j++){
                if(a[j]==b[i] && a[i]%2 !=a[j]%2){
                    swap(a[i],a[j]);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
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