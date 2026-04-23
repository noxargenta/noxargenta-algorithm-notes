#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool different(string& s1,string& s2){
    int dif=0;
    for(size_t i=0;i <s1.length();i++){
        if(s1[i]!=s2[i]){
            dif++;
        }
    }
    return dif==1;
}
void solve() {
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    sort(s.begin(),s.end());
    do {
        bool ok=true;
        for(int i=1;i<n;i++){
        if(!different(s[i],s[i-1])){
            ok=false;
            break;
            }
        }
        if(ok==1){
            cout << "Yes";
            return;
        }
    }while(next_permutation(s.begin(),s.end()));
    cout << "No";
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