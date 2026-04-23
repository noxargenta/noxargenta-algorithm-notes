#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> p(n+1);
    for(int i=1;i<=n;i++){
        int opt,x,y;
        cin >> opt;
        if(opt==1){
            cin >> x;
            p[i]={x+1,n};
        }else if(opt==2){
            cin >> y;
            p[i]={0,y+1};
        }else {
            cin >> x >> y;
            p[i]={x+1,y+1};
        }
    }
    sort(p.begin()+1,p.end());
    priority_queue<int,vector<int>,greater<int>> q;
    int j=1;
    for(int i=1;i<=n;i++){
        while(j<=n && p[j].first<=i){
            q.push(p[j].second);
            j++;
        }   
        if(q.empty() || q.top()<i){
            cout << "N\n"; 
            return;
        }
        q.pop();
    }
    cout << "Y\n"; 
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