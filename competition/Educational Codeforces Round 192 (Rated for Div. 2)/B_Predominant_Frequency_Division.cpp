#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // P1 to keep track of count(1) - count(2) - count(3)
    vector<int> P1(n);
    // P2 to keep track of count(1) + count(2) - count(3)
    vector<int> P2(n);

    int current_p1 = 0;
    int current_p2 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            current_p1 += 1;
            current_p2 += 1;
        } else if (a[i] == 2) {
            current_p1 -= 1;
            current_p2 += 1;
        } else if (a[i] == 3) {
            current_p1 -= 1;
            current_p2 -= 1;
        }
        P1[i] = current_p1;
        P2[i] = current_p2;
    }

    int max_p2 = -1e9;
    bool possible = false;
    
    // We want to find an i and j such that 0 <= i < j <= n - 2
    // Iterating backwards establishes a progressive suffix maximum for P2[j]
    for (int i = n - 3; i >= 0; i--) {
        int j = i + 1;
        max_p2 = max(max_p2, P2[j]);
        
        // Verifying conditions for Part A and Part B correspondingly
        if (P1[i] >= 0 && max_p2 >= P2[i]) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}