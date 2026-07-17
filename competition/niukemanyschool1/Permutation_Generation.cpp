#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long

int sum(vector<int> x,int mod){
    int summ=0;
    for(int i=0;i<x.size();i++){
        summ+=x[i]*(2*i+1)%mod;
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
    for(int i=0;i<n;i++){
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
    if(((f1+n)%n)==((f2+n)%n)){
        for(auto x : a){
            cout << x << " ";
        }
        cout << endl;
    }
    
    bool ok=0;
    for(int i=0;i<n;i++){

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