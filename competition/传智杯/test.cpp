#include <bits/stdc++.h>
using namespace std;
int erjin(string x){
    int sum=0;
    int num=1;
    for(int i=x.size()-1;i>=0;i--){
        
        int t=x[i]-'0';
        if(t==0){
            num++;
            continue;
        }else {
            t=1;
            for(int j=1;j<num;j++){
               t*=2; 
            }
            sum+=t;
            num++;
        }
        
    }
    return sum;
}
int main(){
    string s;
    cin >> s;
    string t;
    cout << erjin(s);
}