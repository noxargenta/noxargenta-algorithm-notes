    #include <bits/stdc++.h>
    using namespace std;
    using i64 = long long;
    #define endl '\n'
    #define int long long
    const int n=2021041820210418;
    void solve() {
        vector<int> a;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                a.push_back(i);
                if(n/i != i ){
                    a.push_back(n/i);
                }
            }
        }
        int sum=0;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a.size();j++){
                for(int k= 0;k<a.size();k++){
                    if(a[i]*a[j]*a[k]==n){
                        sum++;
                    }
                }
            }
        }
        cout << sum << endl;
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