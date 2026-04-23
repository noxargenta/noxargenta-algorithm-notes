#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    unsigned long long x;
    cin >> s >> x;
    int sh  =  x%26;
    for (int i=0 ; i < s.size();i++){
        int num=s[i]- 'a';
        num =( num + sh)%26;
        s[i]=num + 'a';
    }
    cout <<s;
    return 0;
}