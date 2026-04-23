#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n,l,r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int sum=0;
    for(int i=0;i<n;){
        int t=a[i];
        int num=t;
        if(num<l){
            for(int j=i+1;j<n;j++){
                num += a[j];
                if(num>=l && num<=r){
                    sum ++;
                    i=j+1;
                    break;
                }else if(num > r){
                    i=j+1;
                    break;
                }
            }
        }else if(num>=l && num<=r){
            sum ++;
            i++;
        }else if(num>r){
            i++;
        }else {
            i++;
        }
    }
    cout << sum << endl;
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