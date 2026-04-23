#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
struct point {
    i64 x, y;
};

i64 pingfang(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

void solve() {
    point A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    i64 AB =pingfang (A,B);
    i64 AC = pingfang(A,C);
    i64 BC = pingfang(B,C);
    if (AB + AC == BC || AB + BC == AC || AC + BC == AB) {
        cout << "Yes";
    } else {
        cout << "No";
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