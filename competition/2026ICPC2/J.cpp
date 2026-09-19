#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<string,ll> mp;
void solve(){
    ll n,p;
    cin >> n >> p;
    string s;
    ll ans=0;
    while(n--){
        cin >> s;
        if(s[(ll)s.length()-1]>='A' && s[(ll)s.length()-1] <='L'){
            s[(ll)s.length()-1]='X';
            ans+=mp[s];

        }else {
            ans+=mp[s];
        }
    }
    if(ans>p){
        cout << "Joker\n";
    }else {
        cout << "Judger\n";
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll _=1;
    mp["WrongProblemX"]+=100;
    mp["SameProblemX"]+=30;
    mp["UnreasonableProblemArrangement"]+=10;
    mp["UnreasonableLimitForProblemX"]+=5;
    mp["WeakTestsForProblemX"]+=3;
    mp["BadProblemX"]++;
    cin >> _;
    while(_--){
        solve();
    }
}
// WrongProblemX	                 100
// SameProblemX	                         30
// UnreasonableProblemArrangement	    10
// UnreasonableLimitForProblemX        5
// WeakTestsForProblemX	                3
// BadProblemX	                       1
   