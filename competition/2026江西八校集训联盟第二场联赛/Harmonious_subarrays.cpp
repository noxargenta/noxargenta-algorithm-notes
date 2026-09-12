#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
int kmpCount(const string& string1, const string& string2) {
    if (string2.empty()) return 0;

    int n = string1.length();
    int m = string2.length();

    // 1. 构建 next 数组
    vector<int> nxt(m, 0);
    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && string2[i] != string2[j]) {
            j = nxt[j - 1];
        }
        if (string2[i] == string2[j]) {
            j++;
        }
        nxt[i] = j;
    }

    // 2. 匹配并计数
    int count = 0;
    j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && string1[i] != string2[j]) {
            j = nxt[j - 1];
        }
        if (string1[i] == string2[j]) {
            j++;
        }

        // 成功匹配一个完整的模式串
        if (j == m) {
            count++;
            j = nxt[j - 1]; // 允许重叠匹配（例如 "aba" 在 "ababa" 中算 2 次）
        }
    }

    return count;
}

void solve() {
    ll n,m,q;
    cin >> n >> m >> q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    vector<ll> b(m);
    for(ll i=0;i<m;i++){
        cin >> b[i];
    }
    vector<ll> prea;
    vector<ll> preb;
    
    string aa="",bb="";
    for(ll i=1;i<n;i++){
        prea.push_back(a[i]-a[i-1]);
        //aa+=a[i]-a[i-1];
    }
    for(ll i=1;i<n;i++){
        preb.push_back(b[i]-b[i-1]);
        bb+=b[i]-b[i-1]-'0';
    }
    while(q--){
        ll l,r;
        cin >> l >>r;
        aa="";
        if(r-l+1<m){
            cout << 0 <<endl;
            continue;
        }
        for(ll i=l;i<r;i++){
            aa+=prea[i]-'0';
        }
        cout << kmpCount(aa,bb)<<endl;
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