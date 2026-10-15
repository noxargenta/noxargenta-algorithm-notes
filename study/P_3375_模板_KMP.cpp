#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void solve() {
    
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

 /*
2 * next[] 的含义：x[i-next[i]...i-1]=x[0...next[i]-1]
3 * next[i] 为满足 x[i-z...i-1]=x[0...z-1] 的最大 z 值（就是 x 的自身匹配）
4 */
5 void kmp_pre(char x[],int m,int next[]){
6 int i,j;
7 j=next[0]=−1;
8 i=0;
9 while(i<m){
10 while(−1!=j && x[i]!=x[j])j=next[j];
11 next[++i]=++j;
12 }
13 }
14 /*
15 * kmpNext[i] 的意思:next'[i]=next[next[...[next[i]]]](直到
next'[i]<0 或者 x[next'[i]]!=x[i])
16 * 这样的预处理可以快一些
17 */
18 void preKMP(char x[],int m,int kmpNext[]){
19 int i,j;
20 j=kmpNext[0]=−1;
21 i=0;
22 while(i<m){
23 while(−1!=j && x[i]!=x[j])j=kmpNext[j];
24 if(x[++i]==x[++j])kmpNext[i]=kmpNext[j];
25 else kmpNext[i]=j;
26 }
27 }
28 /*
29 * 返回 x 在 y 中出现的次数，可以重叠
30 */
31 int next[10010];
32 int KMP_Count(char x[],int m,char y[],int n){//x 是模式串，y 是主串
33 int i,j;
34 int ans=0;
35 //preKMP(x,m,next);
36 kmp_pre(x,m,next);
37 i=j=0;
38 while(i<n){
39 while(−1!=j && y[i]!=x[j])j=next[j];
40 i++;j++;
41 if(j>=m){
42 ans++;
43 j=next[j];
44 }
45 }
46 return ans;