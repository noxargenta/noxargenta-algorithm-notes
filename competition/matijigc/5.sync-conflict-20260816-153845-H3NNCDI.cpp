#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    string s;
    cin >>s;
    s="0"+s;
    vector<int> a(n+1,0);
    vector<int> b;//下标
    vector<bool> del(n+1,0);
    vector<int> pre(n+1,0);
    int sum=0;
    int last=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        sum+=a[i];
        pre[i]=pre[i-1]+a[i];
        if(a[i]<0){
            b.push_back(i);
        }
    }
    //////
    // for(int i=1;i<=n;i++){
    //     cout << "a[]" << a[i] << " ";
    // }
    // cout <<endl;
    // for(int i=1;i<=n;i++){
    //     cout << "pre[]" << pre[i] << " ";
    // }
    // cout <<endl;
    /////
    for(auto x:b){
        int a1=0;
        int b1=0;
        int c1=0;
        if(s[x]=='a'){
            a1++;
            for(int i=x+1;i<=n;i++){
                if(del[i])continue;
                if(s[i]=='a')a1++;
                else if(s[i]=='b')b1++;
                else c1++;
                if(a1==b1+c1){
                    if(sum-(pre[i]-pre[x-1])>=sum){
                        // cout << "i:" << i << endl;
                        // cout << "pre[i]-pre[x-1])" << pre[i]-pre[x-1] <<endl;
                        // cout << "sum:" << sum << endl;
                        sum=max(sum,sum-(pre[i]-pre[x-1]));
                        for(int j=x;j<=i;j++){
                            del[j]=1;
                        }
                        last=i;
                        break;
                    }
                }
            }
        }else {
            if(s[x]=='b'){
                b1++;
            }else {
                c1++;
            }
            if(del[x])continue;
            for(int i=x-1;i>=1;i--){
                if(del[i])continue;
                if(s[i]=='a')a1++;
                else if(s[i]=='b')b1++;
                else c1++;
                if(a1==b1+c1){
                    if(sum-(pre[x]-pre[i-1])>=sum){
                        // cout << "i:" << i << endl;
                        // cout << "pre[x]-pre[i-1])" << pre[x]-pre[i-1] <<endl;
                        // cout << "sum:" << sum << endl;
                        sum=max(sum,sum-(pre[x]-pre[i-1]));
                        for(int j=x;j>=i;j--){
                            del[j]=1;
                        }
                        last=i;
                        break;
                    }
                }
            }
        }
    }
    cout <<sum <<endl;
}

signed main() {
//  freopen("../dataw/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}