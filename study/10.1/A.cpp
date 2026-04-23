#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a;
    int b;
    int sum;
    for (int i=0;i<n;i++,a=0,b=0 ) {
        cin >> a >> b;
        sum = a + b;
        cout << sum << "\n";
    }
    return 0;
}