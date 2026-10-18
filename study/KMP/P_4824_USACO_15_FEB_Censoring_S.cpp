#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
struct Node{
    char c1;
    ll i;
    char c2;
    ll j;
};
void solve() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    ll n=s2.length();
    vector<ll> nxt(n+1);
    ll i,j;
    j=nxt[0]=-1;
    i=0;
    while(i<n){
        while(j!=-1 && s2[i]!=s2[j]){
            j=nxt[j];
        }
        nxt[++i]=++j;
    }
    stack<Node> st;
    i=0;j=0;
    while(i<s1.length()){
        while(j!=-1 && s1[i]!=s2[j]){
            j=nxt[j];
        }
        st.push({s1[i], i, '\0', j});
        // if(s1[i]==s2[j]){
        //     st.push({s1[i],(ll)i,s2[j],(ll)j});
        // }
        i++;
        j++;
        if(j>n){
            ll xxx=n;
            while(xxx--){
                st.pop();
            }
            j=st.top().j+1;
        }

    }
    string ans="";
    while(!st.empty()){
        ans+=st.top().c1;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
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