#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    deque<int> s;
    for(int i=0;i<n;i++){
        if(!s.empty() && s.front()<=i-k){
            s.pop_front();
        }
        while(!s.empty() && a[s.back()]>=a[i]){
            s.pop_back();
        }
        s.push_back(i);
        if(i>=k-1){
            cout << a[s.front()] << " ";
        }
    }
    cout << endl;
    s.clear();
    for(int i=0;i<n;i++){
        if(!s.empty() && s.front()<=i-k){
            s.pop_front();
        }
        while(!s.empty() && a[s.back()]<=a[i]){
            s.pop_back();
        }
        s.push_back(i);
        if(i>=k-1){
            cout << a[s.front()] << " ";
        }
    }
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;_
    while(_--) {
        solve();
    }
    return 0;
}