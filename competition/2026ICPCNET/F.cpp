#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n,m,cnt=0,pre=0;
    cin>>n>>m;
    vector<ll> scores(n+1,0);
    for(ll i=1;i<=n;i++){
        ll sum=0;
        for(ll j=1;j<=m;j++){
            ll x;
            cin >> x;
            sum+=x;
        }
        if(sum<pre) cnt++;
        pre=sum;
    }
    cout<<cnt<<endl;
    return 0;
}