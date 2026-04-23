#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
struct Node{
    int val,id,rank;
};
void solve() {
    int n;
    cin >> n;
    vector<Node> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].val;
        a[i].id=i+1;
    }
    sort(a.begin(),a.end(),[&](Node x,Node y){
        return x.val<y.val;
    });
    int last=0;
    for(int i=0;i<n;i++){
        if(i==0){
            a[i].rank=1;
            last=i;
        }
        if(a[i].val==a[last].val){
            a[i].rank=a[last].rank;
        }else {
            a[i].rank=i+1;
            last=i;
        }
    }
    sort(a.begin(),a.end(),[&](Node x ,Node y){
        return x.id<y.id;
    });
    for(int i=0;i<n;i++){
        cout << a[i].rank << ' ';
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