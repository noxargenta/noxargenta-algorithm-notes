#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n,mexx;
vector<ll> b;
vector<int> cnt;
vector<ll> val;
vector<int> num;
vector<int> ans;

int calc(ll k){
    ll s=k-mexx;

    int p=upper_bound(val.begin(),val.end(),s)-val.begin()-1;

    for(int d=0;d<n-mexx;d++){
        int x=mexx+d;
        ll y=s-d;

        while(p>=0 && val[p]>y){
            p--;
        }

        int cy=0;
        if(p>=0 && val[p]==y){
            cy=num[p];
        }

        int cx=cnt[x];

        if(y<0){
            if(cx==0){
                return x;
            }
        }
        else if(x==y){
            if(cx==0){
                return x;
            }
        }
        else if(x<y){
            if(cx+cy==0){
                return x;
            }
        }
        else{
            if(cx+cy<2){
                return x;
            }
        }
    }

    return n;
}

void solve(){
    cin>>n;

    b.resize(n);
    cnt.assign(n+1,0);

    for(int i=0;i<n;i++){
        cin>>b[i];

        if(b[i]<=n){
            cnt[b[i]]++;
        }
    }

    mexx=0;

    while(mexx<n && cnt[mexx]){
        mexx++;
    }

    sort(b.begin(),b.end());

    val.clear();
    num.clear();

    for(int i=0;i<n;){
        int j=i;

        while(j<n && b[j]==b[i]){
            j++;
        }

        val.push_back(b[i]);
        num.push_back(j-i);

        i=j;
    }

    ans.resize(val.size());

    for(int i=0;i<(int)val.size();i++){
        ll k=mexx+val[i];

        ans[i]=calc(k);
    }

    ll q;
    cin>>q;

    ll res=0;

    while(q--){
        ll k;
        cin>>k;

        ll s=k-mexx;

        int id=lower_bound(val.begin(),val.end(),s)-val.begin();

        if(id==(int)val.size() || val[id]!=s){
            res^=mexx;
        }
        else{
            res^=ans[id];
        }
    }

    cout<<res<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    while(T--){
        solve();
    }

    return 0;
}