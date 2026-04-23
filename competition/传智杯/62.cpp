#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int r=-1,e=-1,d=-1;
    long long res=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='d'){
            d=i;
        }else if(s[i]=='r'){
            r=i;
        }else if(s[i]=='e'){
            e=i;
        }
        if(min(r,e)>d){
            res+=(long long)(min(r,e)-d);
        }
    }
    cout << res;
    return 0;
}