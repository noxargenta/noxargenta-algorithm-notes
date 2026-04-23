#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n,m,l;
const int v=1000010;
int a[v];

bool ok(int x){
    int out = 0;
    int back = 0;
    for(int i=1;i<n+2;i++){
        if(a[i]-a[back]<x){
            out++ ;
        }else{
            back=i;
        }
    }
    return out <=m;
}

signed main() {
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = l;
    int low=0,high=2*l+999;
    while(low<high-1){
        int mid=low + (high-low)/2;
        if(ok(mid)){
            low=mid;
        }else {
            high=mid;
        }
    }
    cout << low;
    return 0;
}