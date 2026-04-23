#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    stack<char> k;
    for(char x : s) {
        if(x=='(' ||x== '{' || x== '['){
        k.push(x);
        }else if(k.empty()){
            cout << "NO";
            return 0;
        }else{
            char top=k.top();
        k.pop();
        if((x==')' && top!='(') || (x=='}' && top!='{') || (x==']' && top!= '[')){
            cout << "NO";
            return 0;
        }
        } 
    }
    if(k.empty()){
        cout <<"YES";
    }else {
        cout << "NO";
    }
    return 0;
}