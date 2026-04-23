#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,l;
    cin >> n >> l;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(l>=a[i]){
            l++;
        }
    }
    cout << l << " ";
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")