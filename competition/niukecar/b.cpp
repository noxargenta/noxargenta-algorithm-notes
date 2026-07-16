#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n,x;
    cin >> n >> x;
    int tsum=0;
    int ssum=0;
    for(int i=n;i>=1;i--){
        tsum+=(i*26);
        if(tsum>=x){
            break;
        }
        if(n==1 && tsum<x){
            cout << -1 << endl;
            return;
        }
    }
    if((n+1)*n/2>x){
        cout << -1 << endl;
        return;
    }
    string s;
    int sum=0;
    for(int i=n;i>=1;i--){
        char c;
        bool ok=0;
        for(int j=26;j>=1;j--){
            if((sum+j*i+((i-1)+(1))*(i-1)/2)<=x){
                c='a'+j-1;
                s+=c;
                sum+=j*i;
                break;
                ok=1;
            }
        }

    }
    for(int i=s.length()-1;i>=0;i--){
        cout << s[i]; 
    }
    cout << endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}