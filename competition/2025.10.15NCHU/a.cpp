#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long a,b;
    cin >> a >>b;
    priority_queue<unsigned long long> x;
    for (unsigned long long i=0;i<a;i++){
        unsigned long long t;
        cin >>t;
        x.push(t);
    }
    unsigned long long num=0;
    for (unsigned long long i=0;i<b;i++){
        num+=x.top();
        x.pop();
    }
    cout << num;
    return 0;
}