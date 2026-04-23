#include <iostream>
#include <cctype>
using namespace std;
int main(){
    string abc;
    cin >> abc;
    int x=1;
    for (int i=0; i<abc.length(); i++, x++){
        if(isupper(abc[i])){
            cout<<x;
            break;
        }
    }
    return 0;
}