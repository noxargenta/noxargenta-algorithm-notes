#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
unordered_map<int,pair<int,int>> mp;
//a,b,c
//数字，能达到a的个数为b，全部到达a需要的步骤数； 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        int cnt=0;
        if(x==1){
            mp[1].first++;
            mp[1].second+=cnt;
            cnt++;
            mp[2].first++;
            mp[2].second++;
            continue;
        }
        while(x!=1){
            mp[x].first++;
            mp[x].second+=cnt;
            cnt++;
            if(x%2==0){
                x/=2;
            }else {
                x++;
            }
        }
        mp[1].first++;
        mp[1].second+=cnt;
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