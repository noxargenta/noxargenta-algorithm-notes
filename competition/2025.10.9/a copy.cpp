#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main(){
    i64 x;
    cin >> x;
    i64 a1=1,a2=1,a3=2,a4=3,ta1=0,ta2=0,ta3=0,ta4=0;
    i64 count=2;
    if (x<144){
        cout << "2";
    }else{
        for (;a4<x;){
            ta1=a1;
            ta2=a2;
            ta3=a3;
            ta4=a4;
            a4=ta3+ta4;
            a3=ta2+ta3;
            a2=ta1+ta2;
            a1=ta2;
            double r=sqrt(a4);
            i64 l=r;
            if (a4 >=1 && a4<=x && l==r){
                count ++;
            }
        }
        cout << count;
    }
    return 0;
}