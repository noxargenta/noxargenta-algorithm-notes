#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
int rev(int p,bool odd){
    string s=to_string(p);
    string s2=s;
    reverse(s2.begin(),s2.end());
    if(odd){
        return stoll(s+s2.substr(1));
    }else {
        return stoll(s+s2);
    }
}
void solve() {
    int n;
    cin >> n;
    if(n<20){
        for(int a=n;a>=0;a--){
            if((n-a)%12==0){
                string s=to_string(a);
                string r=s;
                reverse(r.begin(),r.end());
                if(r==s){
                    cout << a << ' ' << n-a << endl;
                    return;
                }
            }
        }
        cout << -1 << endl ;
        return;
    }
    string s=to_string(n);
    int L=s.length();
    int mid=(L+1)/2;
    int p=stoll(s.substr(0,mid));
    bool odd=(L%2!=0);
    vector<int> a;
    for(int i=0;i<=100000;i++){
        if(p-i>=0){
            a.push_back(rev(p-i,odd));
        }
    }
    if(L>1){
        a.push_back(stoll(string(L-1,'9')));
    }
    for(auto x : a){
        if(x<=n && (n-x)%12==0){
            cout << x << " " << n-x << endl;
            return;
        }
    }
    cout << -1 << endl;
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