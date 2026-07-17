#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int sum(vector<int> x,int mod){
    int summ=0;
    for(int i=0;i<x.size();i++){
        summ+=x[i]*(2*i+1-mod);
    }
    return summ;
}
void solve() {
    int n,k,x;
    cin >> n  >> k >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int f1=sum(a,n);
    vector<int> I,VAL;
    for(int i=0;i<n;i++){
        if(i!=k){
            I.push_back(i);
        }
        if(i!=x){
            VAL.push_back(i);
        }
    }
    vector<int> b(n);
    deque<int> dq(VAL.begin(),VAL.end());
    b[k]=x;
    for(int i=0;i<I.size();i++){
        int j=I[i];
        if(i%2==0){
            b[j]=dq.front();
            dq.pop_front();
        }else {
            b[j]=dq.back();
            dq.pop_back();
        }
    }
    int f2=sum(b,n);
    if(((f1%n+n)%n)==((f2%n+n)%n)){
        for(auto x : b){
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    
    bool ok=0;
    for(int i=0;i<n;i++){
        if(i==k)continue;
        for(int j=i+1;j<n && j<i+500;j++){
            if(j==k)continue;
            int change=2*(b[i]-b[j])*(j-i)%n;
            if((change%n+n)%n==((f1-f2)%n+n)%n){
                swap(b[i],b[j]);
                ok=1;
                break;
            }
        }
        if(ok==1){
            break;
        }
    }
    if(ok==1){
        for(int i=0;i<n;i++){
            cout << b[i] <<  " " ; 
        }
    }else {
        cout << -1 << endl;
    }
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}