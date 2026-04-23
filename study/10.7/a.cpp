#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    int m;
    cin >> n >> m;
    set<int> a;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    vector <int > miss;
    for (int i = 1; i <= n; i++) {
        if (a.find(i) == a.end()) {
            miss.push_back(i);
        }
    }
    cout  << miss.size() << "\n";
    if (!miss.empty()){
        for (int i=0; i< miss.size(); i++){
            cout << miss[i] << (i==miss.size()-1 ? "" : " ");
        }
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
// 问题陈述
// 给定一个整数序列 
// M
// M 
// A
// =
// (
// A
// 1
// ,
// A
// 2
// ,
// …
// ,
// A
// M
// )
// A=(A 
// 1
// ?
//  ,A 
// 2
// ?
//  ,…,A 
// M
// ?
//  )。
// 每个元素 
// A
// A 是一个介于 
// 1
// 1 和 
// N
// N 之间的整数（包括 
// 1
// 1 和 
// N
// N），且所有元素都是不同的。

// 列出所有在 
// 1
// 1 和 
// N
// N 之间且不出现在 
// A
// A 中的整数，按升序排列。

// 约束条件
// 所有输入值都是整数。
// 1
// ≤
// M
// ≤
// N
// ≤
// 1000
// 1≤M≤N≤1000
// 1
// ≤
// A
// i
// ≤
// N
// 1≤A 
// i
// ?
//  ≤N
// A
// A 的元素是不同的。
// 输入
// 输入通过标准输入给出，格式如下：

// N
// N 
// M
// M
// A
// 1
// A 
// 1
// ?
  
// A
// 2
// A 
// 2
// ?
  
// …
// … 
// A
// M
// A 
// M
// ?
 
// 输出
// 设 
// (
// X
// 1
// ,
// X
// 2
// ,
// …
// ,
// X
// C
// )
// (X 
// 1
// ?
//  ,X 
// 2
// ?
//  ,…,X 
// C
// ?
//  ) 为所有在 
// 1
// 1 和 
// N
// N 之间（包括 
// 1
// 1 和 
// N
// N）且不出现在 
// A
// A 中的整数序列，按升序排列。 输出应为以下格式：

// C
// C
// X
// 1
// X 
// 1
// ?
  
// X
// 2
// X 
// 2
// ?
  
// …
// … 
// X
// C
// X 
// C
// ?
 
// 示例 1
// Inputcopy	Outputcopy
// 10 3
// 3 9 2
// 7
// 1 4 5 6 7 8 10
// 这里是 
// A
// =
// (
// 3
// ,
// 9
// ,
// 2
// )
// A=(3,9,2)。
// 在 
// 1
// 1 和 
// 10
// 10 之间且不出现在 
// A
// A 中的整数，按升序排列，分别是 
// 1
// ,
// 4
// ,
// 5
// ,
// 6
// ,
// 7
// ,
// 8
// ,
// 10
// 1,4,5,6,7,8,10。

// 示例 2
// Inputcopy	Outputcopy
// 6 6
// 1 3 5 2 4 6
// 0

// 在 
// 1
// 1 和 
// 6
// 6 之间没有缺失的整数出现在 
// A
// A 中。
// 在这种情况下，第一行打印 0，第二行留空。

// 示例 3
// Inputcopy	Outputcopy
// 9 1
// 9
// 8
// 1 2 3 4 5 6 7 8
