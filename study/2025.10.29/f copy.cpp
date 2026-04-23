#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDivide(vector<int>& arr, int m, int maxSum) {
    int segments = 1;
    int currentSum = 0;
    
    for (int num : arr) {
        if (num > maxSum) return false;
        
        if (currentSum + num <= maxSum) {
            currentSum += num;
        } else {
            segments++;
            currentSum = num;
            if (segments > m) return false;
        }
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    int left = 0, right = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        left = max(left, arr[i]);
        right += arr[i];
    }
    
    int answer = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canDivide(arr, m, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}