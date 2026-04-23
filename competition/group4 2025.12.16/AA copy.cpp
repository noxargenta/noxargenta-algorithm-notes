#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const int INF=200009;
int p[INF];
int d[INF];
bool lian[INF];
int lians[INF];
int a[INF];
int find(int x ){
    if(p[x]==x){
        return x;
    }
    return p[x]=find(p[x]);
}
void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        p[i]=i;
        d[i]=0;
        lians[i]=1;
        lian[i]=false;
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
        int x=a[i];
        d[i]++;
        d[a[i]]++;//Á¬½ÓÊı;
        int a=find(i);
        int b=find(x);
        if(a!=b){
            p[a]=b;
            lians[b]+=lians[a];
            lians[a]=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(d[i]==1 || lians[find(i)]==2){
            lian[find(i)]=true;
        }
    }
    int x=0,y=0;
    for(int i=1;i<=n;i++){
        if(p[i]==i){
            if(lian[i]==true){
                x++;
            }else {
                y++;
            }
        }
    }
    cout << min(x+y,y+1) << " "<< x+ y << endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}