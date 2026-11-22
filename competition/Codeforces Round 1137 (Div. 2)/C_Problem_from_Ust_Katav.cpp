    #include <bits/stdc++.h>
    using namespace std;
    using i64 = long long;
    #define endl '\n'
    #define ll long long
    #define ull unsigned long long
    void solve() {
        ll n;
        cin >> n;

        vector<ll> p(n+1),L(n+1),R(n+1),st;
        for(ll i=1;i<=n;i++){
            cin >> p[i];

        }

        for(ll i=1;i<=n;i++){
            while(!st.empty() && p[st.back()]>p[i]){
                st.pop_back();
            }
            if(!st.empty()){
                L[i]=st.back();
            }else {
                L[i]=0;
            }
            st.push_back(i);
        }

        st.clear();

        for(ll i=n;i>=1;i--){
            while(!st.empty() && p[st.back()]>p[i]){
                st.pop_back();
            }
            if(!st.empty()){
                R[i]=st.back();
            }else {
                R[i]=n+1;
            }
            st.push_back(i);
        }
        ll ans=0;
        for(ll i=1;i<=n;i++){
            ll a=i-L[i]-1;
            ll b=R[i]-i -1;
            if(a==0 || b==0){
                ans+=a+b+1;
            }else {
                ans+=2;
            }
        }
        cout << ans << endl;
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