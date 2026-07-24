#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n;
    cin>>n;
    vector<bitset<35>> vb;
    for(ll i=0;i<n;i++){
        ll t;cin>>t;
        vb.emplace_back(t);
    }
    ll m;cin>>m;
    for(ll i=0;i<m;i++){
        ll op,t;cin>>op>>t;
        bitset<35> tt(t);
        if(op==1){
            for(auto & x:vb){
                x&=tt;
            }
        }
        else if(op==2){
            for(auto & x:vb){
                x|=tt;
            }
        }
        else{
            for(auto & x:vb){
                x^=tt;
            }
        }
        ll sum=0;
        for(ll i=0;i<n;i++){
            vector<ll> pre(36,0);
            pre[0]=vb[i][0];
            for(ll j=1;j<35;j++){
                pre[j]=vb[i][j]-vb[i][j-1];
            }
            ll t=count(pre.begin(),pre.end(),1);
            sum+=t;
        }
        cout<<sum<<endl;
    }
    return 0;
}