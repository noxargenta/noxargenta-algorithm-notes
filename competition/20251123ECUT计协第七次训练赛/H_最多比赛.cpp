#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
struct con{
    int start;
    int end;
};
bool cmp(const con &x,const con &y){
    if(x.end != y.end){
        return x.end < y.end;
    }
    return x.start<y.start;
};
void solve() {
    int n;
    cin >> n;
    vector<con> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].start >> a[i].end;
    }  
    sort(a.begin(),a.end(),cmp);
    int count =0;
    int last=-1;
    for(int i=0;i<n;i++){
        if(a[i].start>=last){
            count++;
            last=a[i].end;
        }
    }
    cout << count;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    //cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}