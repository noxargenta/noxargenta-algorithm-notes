#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n=0;
    cin >>n;
    string a[3][n];
    for(int i=0;i<n;i++){
        cin >> a[0][i];
        a[3][i]=a[0][i];//3ÊÇ0µÄcopy
    }
    string temp;
    cin >> temp;
    for(int i=0;i<n;i++){
        a[1][i] = temp[i];
    }
    
    for(int i=0;i<n;i++){
        if(isdigit(stoi(a[2][i]))){
            int t=stoi(a[2][i]);
            a[0][i]=a[1][i];
            string tempabc=a[1][i];
            for(int j=i+1;j<n;j++){
                if(stoi(a[2][j])==t){
                    a[0][j]=tempabc;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[0][i]!=a[1][i]){
            cout <<"NO";
            return;
        }
    }
    cout << "YES";
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}