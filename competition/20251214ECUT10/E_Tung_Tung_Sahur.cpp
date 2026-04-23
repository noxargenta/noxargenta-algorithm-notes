#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    int l=0;
    for(int i=0;i<s1.size();i++){
        int j=i;
        while(j<s1.size() && s1[i]==s1[j]){
            j++;
        }
        j--;
        int r=l;
        while(r<s2.size() && s2[l]==s2[r]){
            r++;
        }
        r--;
        if(s1[i]!=s2[l]){
            cout << "NO\n";
            return; 
        }
        int len1=j-i+1,len2=r-l+1;
        if(len2>2*len1 || len2<len1){
            cout << "NO\n";
            return;
        }
        i=j;
        l=r+1;
    }
    if(l<s2.size()){
        cout << "NO\n";
    }else {
        cout << "YES\n";
    }
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