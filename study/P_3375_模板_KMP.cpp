#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
void kmp_pre(const string &x, int m,ll next[]) {
    int i = 0, j = -1;
    next[0] = -1;

    while (i < m) {
        while (j != -1 && x[i] != x[j])
            j = next[j];

        next[++i] = ++j;
    }
}

int KMP_Count(const string &x , ll m , const string &y , ll n, ll next[]) {
    kmp_pre(x, m, next);

    int i = 0, j = 0;
    int ans = 0;

    while (i < n) {
        while (j != -1 && y[i] != x[j])
            j = next[j];

        i++;
        j++;

        if (j == m) {
            ans++;
            j = next[j];
        }
    }
    return ans;
}

string s1,s2;

void solve()
{
    cin >> s1 >> s2;
    ll m=s2.length()+1;
    vector<ll> next(s2.length() + 1);
    kmp_pre(s2,m,next.data());
    KMP_Count(s1,m,s2,)
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
