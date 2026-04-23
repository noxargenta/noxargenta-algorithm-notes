#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf=0x7f7f7f7f;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    i64 sum=0;
    int maxa=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
        maxa=max(maxa,a[i]);
    }
    auto check = [&](i64 maxsum) -> bool{
        int duan=1;
        i64 cusum=0;
        for(int num:a){
            if(num>maxsum){
                return false;
            }
            if(cusum+num<=maxsum){
                cusum+=num;
            }else{
                duan++;
                cusum=num;
            }
        }
        return duan<=m;
    };
    i64 l=maxa,r=sum;
    i64 ans=sum;
    while(l<=r){
        i64 mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout << ans;
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
