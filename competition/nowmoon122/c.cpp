#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,m;
    cin >>n >>m;
    vector<int> a(n);
    int fu=0,zheng=0;
    for (int i=0;i<n;i++){
        cin >>a[i];
        if(a[i]>0){
            zheng++;
        }else{
            fu++;
        }
    }
    if(m==zheng){
        cout << "0\n";
        return;
    }else if((zheng-m)>0 && fu!=0){
        cout << zheng -m << endl;
        return;
    }else if((zheng-m)>0 && fu==0){
        cout << "-1\n";
        return;
    }else if(m==n && fu!=0){
        cout << "-1\n";
        return;
    }else if((m-zheng)>0){
        if(fu>=1){
            cout << m-zheng << endl;
        }else {
            cout << "-1\n";
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _ ;
    while(_--) {
        solve();
    }
    return 0;
}