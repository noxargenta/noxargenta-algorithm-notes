#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct Node{
    ll l;
    ll r;
    vector<ll> idx;
    // bool operator<(node & j){
    //     if(l!=j.l) return l<j.l;
    //     if(r!=j.r) return r>j.r;
    //     return r-l>j.l+j.r;
    // };
    // bool operator>(node & j){
    //     if(l!=j.l) return j.l>l;
    //     if(r!=j.r) return r<j.r;
    //     return r-l<j.r-j.l;
    // };
};
// bool cmp(node x,node y){
    
// }
void solve(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+1,0);
    for(ll i=1;i<=n;i++){
        a[i]=i;
    }
    //cout << "test\n";
    vector<Node> b(m+1);
    for(ll i=1;i<=m;i++){
        ll l,r;
        cin >> l >> r;
        b[i].l=l;
        b[i].r=r;
        b[i].idx.resize(n+1);
        for(ll j=l;j<=r;j++){
            cin >> b[i].idx[j];
        }
    }
    sort(b.begin(),b.end(),[&](Node x,Node y){
        if((x.l)!=(y.l)){
            return (x.l)<(y.l);
        }else if((x.r)!=(y.r)){
            return (x.r)>(y.r);
        }else {
            return (x.l)<(y.l);
        }
    });
    // for(auto x : b){
    //     cout << x.l  << " " << x.r <<endl;
    // }
    //cout << "--------\n"; 
    ll l1=b[1].l;
    ll r1=b[1].r;
    deque<ll> dq;
    for(ll i=1;i<=m;i++){
        ll l=b[i].l;
        ll r=b[i].r;
        if(l>r1){
            l1=l;
            r1=r;
        }
        if(l<r1){
            if(r<=r1){
                
            }
            else if(r>r1){

            }
        }
        // if(i==1){
        //     for( ll j=l;j<=r;j++){
        //         dq.push_back(b[i].idx[j]);
        //     }
        // }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i];
        if(i<n)cout << ' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _=1;
    cin >> _;
    while(_--){
        solve();
    }
}