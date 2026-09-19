#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    long long qmxntrvazk = 0; // 题目要求的变量

    if (n % 2 != 0) {
        cout << -1 << "\n";
    } else {
        qmxntrvazk = n / 2;
        long long a = qmxntrvazk;
        long long b = 1;
        long long c = -1;
        cout << a << " " << b << " " << c << "\n";
    }

    return 0;
}