#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    long long count2 = 0;
    long long count3 = 0;
    long long count5 = 0;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        // 分解质因数 2
        while (a > 0 && a % 2 == 0) {
            count2++;
            a /= 2;
        }
        
        // 分解质因数 3
        while (a > 0 && a % 3 == 0) {
            count3++;
            a /= 3;
        }
        
        // 分解质因数 5
        while (a > 0 && a % 5 == 0) {
            count5++;
            a /= 5;
        }
    }
    
    // 结果是三个质因数个数的最小值
    cout << min({count2, count3, count5}) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}