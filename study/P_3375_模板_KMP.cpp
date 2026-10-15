#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void kmp_pre(string x, int m,ll next[]) {
    int i = 0, j = -1;
    next[0] = -1;

    while (i < m) {
        while (j != -1 && x[i] != x[j])
            j = next[j];

        next[++i] = ++j;
    }
}

string s1,s2;

void solve()
{
    cin >> s1 >> s2;
    
    kmp_pre(s2,);
}

signed main()
{
    //  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}

/*
2 * next[] 的含义：x[i-next[i]...i-1]=x[0...next[i]-1]
3 * next[i] 为满足 x[i-z...i-1]=x[0...z-1] 的最大 z 值（就是 x 的自身匹配）
4 */
void kmp_pre(char x[], int m, int next[])
{
    int i, j;
    j = next[0] =-1;
    i = 0;
    while (i < m)
    {
        while (-1 != j && x[i] != x[j])
            j = next[j];
        next[++i] = ++j;
    }
}
/*
15 * kmpNext[i] 的意思:next'[i]=next[next[...[next[i]]]](直到
next'[i]<0 或者 x[next'[i]]!=x[i])
16 * 这样的预处理可以快一些
17 */
void preKMP(char x[], int m, int kmpNext[])
{
    int i, j;
    j = kmpNext[0] =−1;
    i = 0;
    while (i < m)
    {
        while (−1 != j && x[i] != x[j])
            j = kmpNext[j];
        if (x[++i] == x[++j])
            kmpNext[i] = kmpNext[j];
        else
            kmpNext[i] = j;
    }
}
/*
 * 返回 x 在 y 中出现的次数，可以重叠
 */
int next[10010];
int KMP_Count(char x[], int m, char y[], int n)
{ // x 是模式串，y 是主串
    int i, j;
    int ans = 0;
    // preKMP(x,m,next);
    kmp_pre(x, m, next);
    i = j = 0;
    while (i < n)
    {
        while (−1 != j && y[i] != x[j])
            j = next[j];
        i++;
        j++;
        if (j >= m)
        {
            ans++;
            j = next[j];
        }
    }
    return ans;
}