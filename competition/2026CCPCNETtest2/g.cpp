#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mb=20;

void solve(){
  int n;
  cin>>n;
  vector<ll>ans;
  for(int i=1;i<=n;i++){
    ll l=0,r=1e18;
    ll res=1e18;
    while(l<=r){
    ll mid=(l+r)/2;
    cout<<"? "<<mid<<"\n";
    cout.flush();
    ll c;
    cin>>c;
    if(c<i){
        l=mid+1;
    }else{
        res=mid;
        r=mid-1;
    }
    }
    ans.push_back(res);
  }
  cout<<"!"<<" ";
  int m=ans.size();
  for(int i=m-1;i>=0;i--){
    cout<<ans[i];
    cout.flush();
    if(i>0){
      cout<<" ";
      cout.flush();
    }
   
  }
  cout<<endl;
  cout.flush();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _=1;
    //cin>>_;
    while(_--){
        solve();
    }

    return 0;
}