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
// 广度优先搜索（BFS）算法定义如下。

// 考虑一个无向图，顶点编号从 
// 1
// 1 到 
// n
// n。初始化 
// q
// q 为一个新的队列，仅包含顶点 
// 1
// 1，并将顶点 
// 1
// 1 标记为已使用。
// 从队列 
// q
// q 的头部提取一个顶点 
// v
// v。
// 打印顶点 
// v
// v 的索引。
// 以任意顺序遍历所有与 
// v
// v 相邻且尚未标记为已使用的顶点 
// u
// u。将顶点 
// u
// u 标记为已使用，并将其插入到队列 
// q
// q 的尾部。
// 如果队列不为空，从第 2 步继续。
// 否则结束。
// 由于选择每个顶点的邻居的顺序可以变化，因此可能存在多个序列可以被 BFS 打印。

// 在这个问题中，你需要检查给定的序列是否对应于从顶点 
// 1
// 1 开始的给定树的某个有效 BFS 遍历。树 是一个无向图，任意两个顶点之间恰好有一条简单路径。

// 输入
// 第一行包含一个整数 
// n
// n (
// 1
// ≤
// n
// ≤
// 2
// ⋅
// 10
// 5
// 1≤n≤2⋅10 
// 5
//  )，表示树中的节点数量。

// 接下来的 
// n
// −
// 1
// n−1 行描述树的边。每行包含两个整数 
// x
// x 和 
// y
// y (
// 1
// ≤
// x
// ,
// y
// ≤
// n
// 1≤x,y≤n) — 对应边的两个端点。保证给定的图是树。

// 最后一行包含 
// n
// n 个不同的整数 
// a
// 1
// ,
// a
// 2
// ,
// …
// ,
// a
// n
// a 
// 1
// ​
//  ,a 
// 2
// ​
//  ,…,a 
// n
// ​
//   (
// 1
// ≤
// a
// i
// ≤
// n
// 1≤a 
// i
// ​
//  ≤n) — 要检查的序列。

// 输出
// 如果该序列对应于给定树的某个有效 BFS 遍历，则打印 "Yes"（引号仅为清晰），否则打印 "No"（引号仅为清晰）。

// 你可以使用任意大小写打印每个字母（大写或小写）。

// 示例
// Input复制	Output复制
// 4
// 1 2
// 1 3
// 2 4
// 1 2 3 4
// Yes
// Input复制	Output复制
// 4
// 1 2
// 1 3
// 2 4
// 1 2 4 3
// No
// 注意
// 两个示例测试中包含相同的树。

// 在这棵树中，有两个有效的 BFS 排序：

// 1
// ,
// 2
// ,
// 3
// ,
// 4
// 1,2,3,4，
// 1
// ,
// 3
// ,
// 2
// ,
// 4
// 1,3,2,4。
// 排序 
// 1
// ,
// 2
// ,
// 4
// ,
// 3
// 1,2,4,3 不对应于任何有效的 BFS 排序。