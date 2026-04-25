#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
vector<int> G[200005];
int a[200005],b[200005];
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<n;i++){/////
        int v,u;
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++){////
        cin >> a[i];
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        sort(G[i].begin(),G[i].end(),[&](int x,int y){
            return b[x]<b[y]; 
        });
    }
    vector<int> runans;
    runans.push_back(-999);
    queue<int> q;
    q.push(1);
    vector<bool> visit(200005,0);
    while(!q.empty()){
        int u=q.front();
        visit[u]=1;
        q.pop();
        runans.push_back(u);
        for(auto x : G[u]){
            if(visit[x]==1){
                continue;
            }else{
                q.push(x);
                visit[x]=1;
            }
        }   
    }
    for(int i=1;i<=n;i++){
        if(runans[i]!=a[i]){/////////////
            cout << "No\n" << endl;
            return;
        }
    }
    cout << "Yes\n" << endl;
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
/*广度优先搜索(BFS）算法定义如下。
1.考虑一个无向图，顶点编号从1到n。初始化q为一个新的队列，仅包含顶点1，并将顶点1标记为已使用。
2. 从队列g的头部提取一个顶点u。
3.打印顶点v的索引。
4.以任意顺序遍历所有与相邻且尚未标记为已使用的顶点u。将顶点标记为已使用，并将其插入到队列q的尾部。
5.如果队列不为空，从第2步继续。
6.否则结束。
由于选择每个顶点的邻居的顺序可以变化，因此可能存在多个序列可以被BFS打印。
在这个问题中，你需要检查给定的序列是否对应于从顶点1开始的给定树的某个有效BFS遍历。树是一个无向图，任意两个顶点
之间恰好有一条简单路径。
输入
第一行包含一个整数n(1<n≤2·10)，表示树中的节点数量。
接下来的n一1行描述树的边。每行包含两个整数æ和g(1≤,γ≤n)一对应边的两个端点。保证给定的图是树。
最后一行包含n个不同的整数a1,2,..,(1<<n)）一要检查的序列。
输岀
如果该序列对应于给定树的某个有效BFS遍历，则打印"Ye"引号仅为清断），否则打印"N。”(引号仅为清断）。
你可以使用任意大小写打印每个字母（大写或小写）。
示例
Input
[复制
Output
∫复制
12
Yes
Input
▏复制
Output
复制
243
注意
两个示例测试中包含相同的树。
在这棵树中，有两个有效的BFS排序：
.1, 2, 3, 4.
. 1, 3,2,4.
排序1,2,4,3不对应于任何有效的BFS排序。*/