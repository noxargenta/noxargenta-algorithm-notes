#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve(){
    int n;
    cin>>n;
    int s[n][n];
    int s2[n+2][n+2];
    for(int i=0;i<n;i++){
        string row;
        cin>>row;
        for(int j=0;j<n;j++){
            s[i][j]=row[j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            s2[i+1][j+1]=s[i][j];
        }
    }
    for(int j=0;j<n-1;j++){
            s2[1][j+2]=s[0][j];
        }
    for(int i=0;i<n-1;i++){
        s2[i+2][n]=s[i][n-1];
    }               
    for(int j=1;j<n;j++){
        s2[n][j]=s[n-1][j];
    }
    for(int i=1;i<n;i++){
        s2[i][1]=s[i][0];
    }    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<s2[i][j];
        }
        cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while(_--){
        solve();
    }
    return 0;
}