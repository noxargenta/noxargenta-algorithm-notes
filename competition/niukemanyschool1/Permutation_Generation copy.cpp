#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k,x;
ll pre_sum(vector<ll> a){
    ll len=a.size(),sum=0;
    for(ll i=0;i<len;i++){
        for(ll j=i+1;j<len;j++){
            sum+=(a[j]-a[i]);
        }
    }
    return sum;
}
ll line(ll ix){
    return n-1-ix;
}
ll slope(ll ix){
    return ix;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k>>x;
    vector<ll> a(n,0);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll w1=pre_sum(a);
    w1%=n;
    cout<<w1<<endl;
    vector<ll> b(n,0);
    b[k]=x;
    vector<ll> cub(n,0);
    ll now=(slope(k)-line(k))*x;
    now%=n;
    for(ll i=0;i<n;i++){
        cub[i]=(slope(i)-line(i));
    }
    for(ll i=0;i<n;i++){
        cout<<cub[i]<<" ";
    }
    cout<<endl;
    ll rl=(n-2)/2;
    ll dis=(w1+n-now)%n;
    if(k<=rl){
        for(ll i=n-1;i>rl;i--){
            if(i==k) continue;
            ll t=dis/cub[i];
            b[i]=t;
            dis-=(t*cub[i]);
        }
        if(dis!=0) cout<<-1<<endl;
        else{
            for(ll i=0;i<n;i++){
                cout<<b[i];
                if(i!=n-1) cout<<" ";
            }
            cout<<endl;
        }
    }
    else{
        ll dis=(now-(w1-n))%n;
        for(ll i=0;i<=rl;i++){
            if(i==k) continue;
            ll t=(dis/cub[i]);
            b[i]=t;
            dis-=(t*cub[i]);
        }
        if(dis!=0) cout<<-1<<endl;
        else{
            for(ll i=0;i<n;i++){
                cout<<b[i];
                if(i!=n) cout<<" ";
            }
            cout<<endl;
        }
    }
    cout<<endl;
    return 0;
}