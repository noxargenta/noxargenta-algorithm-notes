#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1),ma,mi;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int sum=0;
    int pre;
    for(int i=1;i<=n;i++){
        if(i==1 && a[2]<0){
            pre=a[1];
            sum+=a[1];
            ma.push_back(0);
            continue;

        }
        if(a[i]*pre<0){
            if(a[i]>0){
                mi.push_back(sum);
                sum+=a[i];
                pre=a[i];
                continue;
            }else if(a[i]<0){
                ma.push_back(sum);
                sum+=a[i];
                pre=a[i];
                continue;
            }
        }
        sum+=a[i];
        pre=a[i];
    }
    if(ma.size()!=mi.size()){
        mi.push_back(ma[ma.size()]);
    }
    int ans=0;
    for(int i=0;i<=ma.size();i++){
        int cha=0;
        int x=ma[i];
        for(int i=1;i<=ma.size();i++){
            if(ma[i]>x){
                cha+=min(ma[i]-x,ma[i]-mi[i]);
            }
        }
        if(i==1){
            continue;
            pre=cha;
            ans=x;
        }
        if(cha<pre){
            ans=x;
        }
    }
    cout << ans << endl;
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