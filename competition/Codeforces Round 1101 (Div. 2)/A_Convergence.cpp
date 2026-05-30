#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // 1. 排序，方便两端双指针向中间靠拢
    sort(a.begin(), a.end());
    
    int sixseven = 0; // 通话次数
    int left = 0, right = n - 1;
    
    // 2. 双指针模拟
    while (left < right) {
        if (a[left] != a[right]) {
            sixseven++;
            left++;
            right--;
        } else {
            // 如果最左边和最右边已经相等，说明剩下的所有人都在同一个位置了
            break;
        }
    }
    
    cout << sixseven << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}