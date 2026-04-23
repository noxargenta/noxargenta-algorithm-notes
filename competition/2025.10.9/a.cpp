#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main(){
    int x;
    cin >> x;
    int count=2;
    vector<i64> a(x);
    for (int i=0;i<x;i++){
        a[i]=0;
    }
    a[0]=1;
    a[1]=1;
    if (x<8){
        cout << "2";
    }else {
        for (int i=2;i<x;i++){
                a[i]=a[i-1] + a[i-2];
                if (a[i]>x){
                break;
                }
            }
        for (int i=2;i<x;i++){
            double r=sqrt(a[i]);
            int l=r;
            if (a[i] >=1 && a[i]<=x && l==r){
                count++;
            }
        }
        cout << count;
    }
    // for (int i=0;i<x;i++){
    //     cout << a[i];
    // }
    return 0;
}