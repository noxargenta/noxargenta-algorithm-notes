#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n;
    cin >>n;
    queue<int> a;
    for (int i=0;i<n;i++){
        int t;//1 push 2pop 3query 4size
        cin >>t;
        if (t==1){
            int x=0;
            cin >> x;
            a.push(x);
        }else if(t==2){
                    if (a.empty()){
                        cout << "ERR_CANNOT_POP" <<endl;
                    }else{
                        a.pop();
                    }
                }else if(t==3){
                        if (a.empty()){
                            cout << "ERR_CANNOT_QUERY" << endl;
                        }else{
                            cout << a.front() << endl;
                        }
                        }else {             //4
                            cout << a.size() << endl;
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