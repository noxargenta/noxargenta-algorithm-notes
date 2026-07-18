#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    int sum=0;
    int b1=0,b2=0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    for(int i=1;i<n;i++){
        int x=a[i];
        int t=1;
        int j;
        for(j=i+1;j<=n;j++){
            if(a[j]==x){
                t++;
            }else {
                break;
            }
        }
        i=j-1;
        if(x==1){
            b1+=(t/2);
        }else {
            b2+=(t/2);
        }
    }
    int ch=max(b1,b2);
    if(sum==0){
        cout << "YES\n";
        return;
    }
    if(ch*2>=(abs(sum)) && abs(sum)%4==0){
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }

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