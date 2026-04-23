#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    set<vector<int>> visited;
    queue<pair<vector<int>,int>> q;
    q.push({a,k});
    visited.insert(a);
    int result = *max_element(a.begin(),a.end());
    while(!q.empty()){
        auto [state,remaining] = q.front();
        q.pop();
        
        if(remaining == 0){
            result = max(result,*max_element(state.begin(),state.end()));
            continue;
        }
        
        for(int i=0;i<n-1;i++){
            if(state[i] <= state[i+1]){
                vector<int> new_state = state;
                new_state[i]++;
                
                result = max(result,*max_element(new_state.begin(),new_state.end()));
                
                if(remaining > 1 && visited.find(new_state) == visited.end()){
                    visited.insert(new_state);
                    q.push({new_state,remaining-1});
                }
            }
        }
    }
    
    cout << result << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }

    return 0;
}