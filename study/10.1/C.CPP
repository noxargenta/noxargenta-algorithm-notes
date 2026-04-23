#include <iostream>

using namespace std;

int main(){
    int n = 0, m = 0;
    cin >> n >> m;
    int A[101]; 
    int B[101];
    for (int i = 1; i <= n; i++){
        cin >> A[i]; 
    }
    for (int i = 0; i < m; i++){
        cin >> B[i];
    }
    int sum = 0;
    for (int ib = 0 ;ib < m; ib++){
        sum += A[B[ib]]; 
    }
    cout << sum;
    return 0;
}