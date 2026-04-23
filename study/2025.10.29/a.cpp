#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n>1 && s[0] == '0' && s[1] == '1'){
        cout << "NO\n";
        return;
    }
    if(n>1 && s[n-2] == '1' && s[n-1] == '0'){
        cout << "NO\n";
        return;
    } 
    for(int i=1;i<n-1;i++){
        if(s[i-1] == '1' && s[i] == '0' && s[i+1] == '1'){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    vector<int> a(n+1);
    int i=0;
    while(i<n){
        if(s[i]=='1'){
            a[i+1]=i+1;
            i++;
        }else {
            int start = i;
            int j=i;
            while(j<n && s[j]== '0'){
                j++;
            }
            int end=j-1;
            start++;
            end++;
            a[end] = start;
            for(int k=start ; k< end ; k++){
                a[k]=k+1;
            }
            i=j;
        }
    }
    for(int i=1;i<=n;i++){
        cout << a[i] << (i==n ? "" : " ");
    }
    cout << "\n";
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
