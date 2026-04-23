#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mx=1e5+99;
int n,m;
struct T{
    int l,r;
    int pr;
}t[mx]={0};
void add(int i,int k,int f){
    if(f==1){
        t[k].r=t[i].r;
        t[k].l=i;
        t[i].r=k;
        t[t[k].r].l=k;
    }else {
        t[k].r=i;
        t[k].l=t[i].l;
        t[i].l=k;
        t[t[k].l].r=k;
    }
}
void solve() {
    int x,k,f;
    cin >> n;
    t[0].r=0,t[0].l=0;
    add(0,1,1);
    for(int i=2;i<=n;i++){
        cin >> x >> f;
        add(x,i,f);
    }
    cin >> m;
    while(m--){
        cin >> x;
        t[x].pr=1;
    }
    for(int i=t[0].r;i;i=t[i].r){
        {
            if(t[i].pr==0){
                cout << i  << " "; 
            }
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