#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >>n;
    string s;
    cin >> s;
    int result=2;
    int c1=0,c2=0,c3=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
                c1++;
            }else if(s[i]=='2'){
                c2++;
            }else if(s[i]=='3'){
                c3++;
            }
    }
    if(c1==0 || c2==0 || c3==0){
        cout << -1;
        return;
    }
    for(int i=0;i<n-2;i++){
        set<char> buxiangdeng;
        buxiangdeng.insert(s[i]);
        buxiangdeng.insert(s[i+1]);
        buxiangdeng.insert(s[i+2]);
        int no=buxiangdeng.size();
        int nowno=3-no;
        result=min(nowno,result);
        if (nowno == 0) {
            break;
        }
    }
    cout << result << endl;
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