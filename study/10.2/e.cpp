#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
    int n,q;
    cin >> n >> q;
    int S[100] = {0};
    int a,b;//yello 1 red 2 wen question 3
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        switch(a){
            case 1:
                S[b]++;
                break;
            case 2:
                S[b] += 2;
                break;
            case 3:
                if (S[b] >= 2) {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
                break;
        }
    }
    return 0;
}