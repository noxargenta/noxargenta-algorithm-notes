#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int N;
    if (!(cin >> N)) return;

    struct Rng { i64 L, R; };
    vector<Rng> rngs(N);
    
    i64 Smin = 0;
    i64 Smax = 0;

    for (int i = 0; i < N; ++i) {
        cin >> rngs[i].L >> rngs[i].R;
        Smin += rngs[i].L;
        Smax += rngs[i].R;
    }

    if (Smin > 0 || Smax < 0) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    vector<i64> X(N);
    for(int i = 0; i < N; ++i) {
        X[i] = rngs[i].L;
    }

    i64 Delta = -Smin; 

    for (int i = 0; i < N; ++i) {
        i64 cap = rngs[i].R - rngs[i].L;

        i64 add = min(Delta, cap);

        X[i] += add;

        Delta -= add;

        if (Delta == 0) {
            break;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << X[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}