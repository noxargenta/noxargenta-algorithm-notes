#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    int n;
    cin >> n;
    n/=1000;
    n%=(24*60*60);
    int hours=n/(60*60);
    n%=3600;
    int minutes=n/60;
    n%=60;
    int ss=n;

    // printf 实现: printf("%02d:%02d:%02d\n", 
    //hours, minutes, ss);
    cout << setfill('0')
    <<setw(2)<< hours << ':' 
    <<setw(2)<< minutes << ':' 
    <<setw(2)<< ss << endl;
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