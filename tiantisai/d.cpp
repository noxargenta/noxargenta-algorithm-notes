#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
void solve(){
    int n;
    cin >> n;
    int m=1<<n;///总数是2m个，总共有m/2对子,m里面是0~(m-1);
    vector<int> a((1<<n)*2);
    for(int i=0;i<=(m-1)/2;i++){
        //cout << i << " " << m-1 -i << " ";
        a.push_back(i);
        a.push_back(m-1-i);
        
    }
    for(int i=0;i<=(m-1)/2;i++){
        //cout << 2*i << " " << 2*i+1;
        a.push_back(2*i);
        a.push_back(2*i+1);
        
    }
    // int sum=0;
    // for(int i=0;i<a.size();i+=2){
    //     sum+=(a[i]^a[i+1]);
    // }
    // if(sum==1<<(2*n-1)){
    //     cout << 1 << endl;
    // }
    for(auto x : a){
        cout << x << " ";
    }


    
}
int main(){
    int _=1;
    //cin >> _;
    while(_--){
        solve();
    }
    return 0;
}