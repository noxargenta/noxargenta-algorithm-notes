#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(2*n+1), mx(n+1);
    int mn=n;

    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i+n]=a[i];
        mn=min(mn,a[i]);
    }

    // q 保存仍可能成为答案的起点，mx[p] 
    //是当前
    //前缀最大值
    vector<int> q, nq;
    for(int i=1;i<=n;i++){
        if(a[i]==mn){
            q.push_back(i);
            mx[i]=a[i];
        }
    }

    for(int i=1;i<n&&q.size()>1;i++){
        mn=n;
        for(auto p : q){
            mx[p]=max(mx[p],a[p+i]);
            mn=min(mn,mx[p]);
        }

        nq.clear();
        for(auto p : q){
            if(mx[p]!=mn)continue;

            // 当前结果打平且已读区间重叠，保留靠前的起点
            if(!nq.empty()&&p-nq.back()<=i)continue;

            nq.push_back(p);
        }
        q.swap(nq);
    }

    int s=q[0], ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,a[s+i]);
        cout << ans << (i==n-1?'\n':' ');
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _=1;
    cin >> _;
    while(_--){
        solve();
    }
    return 0;
}