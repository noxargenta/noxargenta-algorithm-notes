#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const int N = 2e4+5;
int fa[N];
map<string,int> mp;
int find(int x){
    if(fa[x]==x){
        return x;
    }else {
        return fa[x]=find(fa[x]);
    }
}
void solve() {
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        mp[s]=i;
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        string s1,s2;
        cin >> s1 >> s2;
        int x=find(mp[s1]);
        int y=find(mp[s2]);
        if(x!=y){
            fa[x]=y;
        }
    }
    int k;
    cin >> k;
    while(k--){
        string s1,s2;
        cin >> s1 >> s2;
        int x=find(mp[s1]);
        int y=find(mp[s2]);
        if(x==y){
            cout << "Yes." << endl;
        }else {
            cout << "No." << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while(_--) {
        solve();
    }
    return 0;
}