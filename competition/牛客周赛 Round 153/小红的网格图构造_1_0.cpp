#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,k,m;
    cin >> n >> m >> k;
    if(k==0){
        if(n==1 || m==1){
            cout << "Yes\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout << "0";
                }
                cout << endl;
            }
            return;
        }else {
            cout << "No\n";
        }
        return;
    }
    int max_k=(n*m+1)/2;
    if(k>max_k){
        cout << "No\n";
        return;
    }
    vector<vector<int>> g(n,vector<int>(m,0));
    int mid=0;
    for(int i=0;i<n;i+=2){
        for(int j=0;j<m;j+=2){
            g[i][j]=1;
            mid++;
        }
    }
    if(k<mid){
        int need=mid-k;
        for(int i=0;i<n;i+=2){
            for(int j=1;j<m-1;j+=2){
                if(need>0){
                    g[i][j]=1;
                    need--;
                }
            }
        }
        if(need>0){
            for(int i=1;i<n-1;i+=2){
                if(need>0){
                    g[i][0]=1;
                    need--;
                }else {
                    break;
                }
            }
        }
    }else if(k>mid){
        int need=k-mid;
        for(int i=1;i<n;i+=2){
            for(int j=1;j<m;j+=2){
                if(need>0){
                    g[i][j]=1;
                    need--;
                }else{
                    break;
                }
            }
            if(need==0){
                break;
            }
        }
    }
    cout << "Yes\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << g[i][j];
        }
        cout << endl;
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