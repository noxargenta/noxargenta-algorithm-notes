    #include <bits/stdc++.h>
    using namespace std;
    using i64 = long long;
    #define endl '\n'
    #define int long long
    int x[100001];
    int y[100001];
    void solve() {
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> x[i] >> y[i];
        }
        for(int i=1;i<n-1;i++){
            int dx=x[i]-x[i-1];
            int dy=y[i]-y[i-1];
            int nx=x[i+1]-x[i];
            int ny=y[i+1]-y[i];
            int chaji=dx*ny-dy*nx;
            if(chaji>0){
                cout << "LEFT ";
            }else if(chaji==0){
                cout << "STRAIGHT ";
            }else if(chaji<0){
                cout << "RIGHT ";
            }
        }
        cout << endl;
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