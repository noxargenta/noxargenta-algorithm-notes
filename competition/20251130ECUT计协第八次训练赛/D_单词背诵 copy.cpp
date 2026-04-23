#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long

void solve() {
    int n;
    cin >> n;
    string s1;
    
    map<string,bool> flag;
    for(int i=0;i<n;i++){
        cin >> s1;
        flag[s1]=1;
    }
    int m;
    cin >> m;
    vector<string> s(m + 1);
    for(int i=1;i<=m;i++){
        cin >> s[i];
    }
    map<string,int> sum;
    int l=1;
    int ans1=0;
    int ans2=0;
    for(int i=1;i<=m;i++){
        if(flag[s[i]]==1){
            sum[s[i]]++;
            
        }   
        if(sum[s[i]]==1){
            ans1++;
            ans2=i-l+1;
        }
        while(l<=i){
            if(!flag[s[l]]){
                l++;
                continue;
            }
            if(sum[s[l]]>=2){
                sum[s[l]]--;
                l++;
                continue;
            }
            break;
        }
        if(ans1 > 0) {
            ans2 = min(ans2, i-l+1);
        }
    }
    cout << ans1 << endl <<ans2;
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