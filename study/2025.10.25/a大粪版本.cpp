#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> s(n);
    vector<int> s2(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<m;i++){
        cin >> s2[i];
    }
    if(n<=10){
        for(int i=0;i<m;i++){
            int res=s2[i];
            for(int j=0;j<n;j++){
                if(s[j]==res){
                    cout << j + 1 << " ";
                    break;
                }
                cout << "-1" << " ";
            }
        }
        return;
    }else{
            for(int i=0;i<m;i++){
                int res=s2[i];
                int l=0,r=s.size()-1;
                while(r-l>=10){
                    if(s[(r+l)/2]==res){
                        r=(r+l)/2;
                        while(r>=l){
                            if(s[r]!=res){
                                cout << r+2 << " " ;
                                break;
                            }else{
                                r--;
                            }
                        }
                        break;
                    }
                    if(s[(r+l)/2]>res){
                        r=(r+l)/2;
                        continue;
                    }else if(s[(r+l)/2]<res){
                        l=(r+l)/2;
                        continue;
                    }
                }
                bool ok=0;
                for(int j=0;j<n;j++){
                    if(s[j]==res){
                        cout << j + 1 << " ";
                        ok=1;
                        break;
                    }
                }
                if(!ok){
                cout << "-1" << " " ; 
                }
            }
    }
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