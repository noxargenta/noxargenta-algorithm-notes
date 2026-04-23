#include <bits/stdc++.h>
using namespace std;
using i64 = unsigned long long;
void solve() {
    stack<i64> a;
        int n2;
        cin >> n2;
        for (int p=0;p<n2;p++){
            string x;
            cin >> x;
            if (x=="push"){
                i64 temp=0;
                cin >> temp;
                a.push(temp);
            }else if(x=="pop"){
                    if(a.empty()){
                        cout << "Empty\n";
                    }else{
                        a.pop();
                    }
                }else if(x=="query"){
                        if(a.empty()){
                            cout << "Anguei!\n";
                        }else{
                            cout << a.top() << endl;
                        }
                        }else{
                            cout << a.size() << endl;
                        }
        }
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 _ = 1;
    cin >> _;
    while(_--){
        solve();
    }
    return 0;
}