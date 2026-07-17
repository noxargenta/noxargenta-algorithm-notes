#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int check(char x){
    if(x=='a' || x== 'e' || x== 'i' || x=='o' || x=='u'){
        return 1;
    }
    return 0;
}
void solve() {
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        int j=i+1;
        if(j%2==1 && check(s[i])==1){
            cout << "Well-Being\n";
            return;
        }else if(j%2==0 && check(s[i])==0){
            cout << "Well-Being\n";
            return; 
        }
    }
    cout << "Suspected Virus\n";
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