#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    int a[n],b[n];
    string ss1,ss2;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ss1+=a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        ss2+=b[i];
    }
    if(ss1==ss2){
        cout << 0 << endl;
        return;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            int sum=a[i];
            int dif=1;
            int j;
            for( j=i+1;j<n;j++){
                if(a[j]!=b[j]){
                    sum+=a[j];
                    dif++;
                }else {
                    break;
                }
            }
            i=j-1;
            if(sum==0){
                cout << "-1\n";
                return;
            }
            if(sum%2==1){
                ans++;
            }else {
                ans+=2;
            }

        }
    }
    cout << ans  << endl;
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
