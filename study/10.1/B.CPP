#include <iostream>
using namespace std;
int main(){
    char s[11];
    cin >> s; 
    for (int i = 0; s[i] != '\0'; i++) {
    if (s[i]=='0'){
            s[i]= '1';
        }else {
            s[i]= '0';
        }
    }
    cout << s;
    return 0;
}