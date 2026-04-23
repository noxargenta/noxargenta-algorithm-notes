#include<bits/stdc++.h>
using namespace std;
long long a[300005];
long long b[300005];
#define endl '\n'
void solve(){
    long long n;
    cin >> n;
    long long ans=0;
    long long minn=1000000000002;
    for(long long i=1;i<=n;i++){
        cin >> a[i] >> b[i];
        if(i>1){
            if(a[i]>b[i-1]){
                ans+=(a[i]-b[i-1]);
                a[i]=b[i-1];
            }
            minn=min(minn,a[i]);
        }
        
    }
    
    // for(int i=1;i<n;i++){
    //     //c[i]=a[i];
    //     if(a[i+1]-b[i]>0){
    //         ans+=(a[i+1]-b[i]);
    //         //c[i+1]=a[i+1]-b[i];
    //         a[i+1]=b[i];
    //     }else {
    //         continue;
    //     }
    // }
    //vector<long long> c(n+1);
    if(a[1]>b[n]){
        ans+=(a[1]-b[n]);
        a[1]=b[n];
    }
    minn=min(minn,a[1]);
    // long long minn=0x7f7f7f7f;
    // for(long long i=1;i<=n;i++){
    //     minn=min(minn,a[i]);
    // }
    cout << ans +minn << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long _=1;
    cin >> _;
    while(_--){
        solve();
    }
    return 0;
}