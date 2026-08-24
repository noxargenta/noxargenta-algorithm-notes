#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// 数组中只有两个数 a、b 出现奇数次，其余数都出现偶数次
// 找出这两个数并输出
pair<int, int> twoOddNumbers(vector<int>& nums) {
    int eor1 = 0;
    for (int num : nums) {
        eor1 ^= num;          // 全部异或 = a ^ b（偶数次的数互相抵消）
    }

    // Brian Kernighan：提取二进制里最右侧的 1
    int rightOne = eor1 & (-eor1);

    // a ^ b 的最右 1 位，a 和 b 在这一位必然一个为 0 一个为 1
    // 按这一位分组，只异或该位为 0 的那组，得到 a（或 b）
    int eor2 = 0;
    for (int num : nums) {
        if ((num & rightOne) == 0) {
            eor2 ^= num;
        }
    }

    int a = eor2;
    int b = eor1 ^ eor2;
    return {a, b};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    auto [a, b] = twoOddNumbers(nums);
    cout << a << " " << b << endl;
    return 0;
}
