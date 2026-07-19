#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    string s,t;
    cin >> s  >> t;
    if(s==t){
        cout << "0\n";
        return;
    }
    int sum=0;
    deque<int> a,b;
    for(int i=0;i<n;i++){
        if(s[i]=='0' && s[i]!=t[i]){
            sum++;
            a.push_back(i+1);
        }else if(s[i]!=t[i] && s[i]=='1'){
            b.push_back(i+1);
        }
        
    }
    int m=a.size();
    cout << 2*m+1 <<endl;
    for (int i=0;i<m;i++) {
        cout << a[i] << endl;
        cout << b[i] << endl;
    }
    cout << a[0] << endl;
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