#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<ll> a;

// cnt[x] = x 在原数组中出现了多少次
unordered_map<ll,int> cnt;

// best[x] = 当 k = mex(a) + x 时，对应的最大 mex
unordered_map<ll,int> best;

// 求一个数组的 mex
int get_mex(){
    vector<int> vis(n+1,0);

    for(auto x:a){
        // mex 最大不会超过 n
        if(0<=x && x<=n){
            vis[x]=1;
        }
    }

    for(int i=0;i<=n;i++){
        if(!vis[i]){
            return i;
        }
    }

    return n;
}

// 求固定 k 时的 k-mex(a)
int calc(ll k){

    int ans=n;

    for(int x=0;x<n;x++){

        ll y=k-x;

        int c1=cnt.count(x)?cnt[x]:0;
        int c2=cnt.count(y)?cnt[y]:0;

        // x 根本造不出来
        if(c1+c2==0){
            ans=min(ans,x);
        }

        /*
            x < y，且 y<n：

            x,y 都可能需要进入 mex。

            但如果总共只有一个元素，
            那么无法同时得到 x 和 y。
        */
        if(x<y && y<n && c1+c2==1){
            ans=min(ans,(int)y);
        }
    }

    return ans;
}

void solve(){

    cin>>n;

    a.resize(n);
    cnt.clear();
    best.clear();

    // 统计每个数出现次数
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }

    // 原数组的 mex
    int M=get_mex();

    /*
        只有 k=M+a[i] 才有可能让答案 > M。

        所以我们只计算这些 k。
    */
    for(auto x:a){
        ll k=M+x;

        // 重复的 x 不需要重复算
        if(!best.count(x)){
            best[x]=calc(k);
        }
    }

    int q;
    cin>>q;

    ll res=0;

    while(q--){

        ll k;
        cin>>k;

        /*
            如果 k-M 不是原数组中的元素，
            就不可能把原来的 mex M 变出来。

            那么答案不可能超过 M。

            由于我们可以选择什么都不变，
            所以答案恰好就是 M。
        */
        ll x=k-M;

        if(x<0 || !cnt.count(x)){
            res^=M;
        }
        else{
            // 这是我们提前计算好的候选 k
            res^=best[x];
        }
    }

    cout<<res<<"\n";
}

signed main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll _;
    cin>>_;

    while(_--){
        solve();
    }

    return 0;
}