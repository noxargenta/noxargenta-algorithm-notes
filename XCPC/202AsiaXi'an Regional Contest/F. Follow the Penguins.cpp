#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<int> to(n + 1);
    //to[i]表示第i只企鹅追to[i]企鹅
    // 反向rev[i]表示i企鹅追的企鹅有rev[i]={x,x,x,x,x}编号

    vector<vector<int>> rev(n + 1);

    for(int i=1;i<=n;i++){
        cin >> to[i];
        rev[to[i]].push_back(i);
    }
    
    // 坐标放大两倍，速度变成每秒 1 个单位
    vector<ll> x(n + 1);
    for(int i=1;i<=n;i++){
        cin >> x[i];
        x[i] *= 2;
    }

    vector<int> dir(n + 1);
    for(int i=1;i<=n;i++){
        dir[i] = (x[to[i]] > x[i] ? 1 : -1);
    }

    const ll INF = (1LL << 62);

    vector<ll> nxt(n + 1, INF);
    vector<ll> ans(n + 1, -1);

    // 已停止企鹅在放大坐标下的停止位置
    vector<ll> pos(n + 1);

    priority_queue<pair<ll,int>,
                   vector<pair<ll,int>>,
                   greater<pair<ll,int>>> pq;

    // 假设目标继续运动，计算初始相遇事件
    for(int i=1;i<=n;i++){
        int j = to[i];

        if(dir[i] != dir[j]){
            nxt[i] = abs(x[i] - x[j]) / 2;
            pq.push({nxt[i], i});
        }
    }

    while(!pq.empty()){
        auto [tm,u] = pq.top();
        pq.pop();

        // 已停止，或者这是过期预测
        if(ans[u] != -1 || tm != nxt[u])continue;

        ans[u] = tm;
        pos[u] = x[u] + 1LL * dir[u] * tm;

        // u 停止，重新计算所有追随者的相遇时间
        for(auto v : rev[u]){
            if(ans[v] != -1)continue;

            ll now = x[v] + 1LL * dir[v] * tm;
            ll nt = tm + abs(pos[u] - now);

            // 新时间可能更大，也可能更小，直接替换
            nxt[v] = nt;
            pq.push({nt, v});
        }
    }

    for(int i=1;i<=n;i++){
        cout << ans[i] << (i == n ? '\n' : ' ');
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
