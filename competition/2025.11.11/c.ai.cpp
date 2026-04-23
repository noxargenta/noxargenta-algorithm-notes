#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> ops;

    if(n<=8){
        // 对于较小的n，使用一个简单策略即可
        // 1. 用a[n]将a[3]...a[n-1]都变成1
        for(int i=3;i<n;i++){
            ops.push_back({i,n});
        }
        
        // 2. 用a[2]将a[n]变成1
        i64 tempn=n;
        while(tempn>1){
            ops.push_back({n,2});
            tempn=(tempn+2-1)/2; // 等价于 ceil(tempn / 2.0)
        }
    } else {
        // 对于较大的n，使用“帮手”策略优化次数
        int k=8; // 选择8作为帮手

        // 步骤1: 用a[n]将除了帮手k以外的a[3]...a[n-1]都变成1
        for(int i=3;i<n;i++){
            if(i!=k){
                ops.push_back({i,n});
            }
        }

        // 步骤2: 用帮手k将a[n]快速变成1
        i64 tempn=n;
        while(tempn>1){
            ops.push_back({n,k});
            tempn=(tempn+k-1)/k;
        }

        // 步骤3: 用a[2]将帮手k变成1
        // k=8, a[k]的值为8 -> 4 -> 2 -> 1, 需要3步
        ops.push_back({k,2});
        ops.push_back({k,2});
        ops.push_back({k,2});
    }

    cout<<ops.size()<<endl;
    for(auto p:ops){
        cout<<p.first<<" "<<p.second<<endl;
    }
}
    

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    cin>>_;
    while(_--) {
        solve();
    }
    return 0;
}