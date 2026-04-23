// 题目描述
// 有一排
// N
// N个人，他们用一个长度为
// N
// N的字符串
// S
// S来描述。如果
// S
// S的第
// i
// i个字符是M，则从前往后数第
// i
// i个人是男性；如果是F，则为女性。

// 请判断男女是否交替排列。

// 当且仅当不存在两个男性或两个女性相邻的位置时，我们称男女是交替排列的。

// 约束条件
// 1
// ≤
// N
// ≤
// 100
// 1≤N≤100
// N
// N为整数
// S
// S是由M和F组成的长度为
// N
// N的字符串
// 输入格式
// 输入通过标准输入给出，格式如下：

// N
// N
// S
// S
// 输出格式
// 如果男女交替排列，输出Yes；否则输出No。

// 样例1
// Inputcopy	Outputcopy
// 6
// MFMFMF
// Yes
// 不存在两个男性或两个女性相邻的位置，因此男女是交替排列的。

// 样例2
// Inputcopy	Outputcopy
// 9
// FMFMMFMFM
// No
// 样例3
// Inputcopy	Outputcopy
// 1
// F
// Yes
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int check=0;
    for (int i=0;i<n-1;i++){
        if (s[i]==s[i+1]){
            check++;
        }
    }
    if (check==0){
        cout << "Yes";
    } else {
        cout << "No";
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