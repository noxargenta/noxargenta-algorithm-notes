#include <bits/stdc++.h>
using namespace std;
long long  erjin(string x){
    long sum=0;
    long num=1;
    for(int i=x.size()-1;i>=0;i--){
        long long t=x[i]-'0';
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
    int num=1;
    vector<long long> a;
    int numxx=0;
    for(int i=0;s.size()-i>=num || (num > 10 && i+1<=s.size());){
        if(num>10){
            t.push_back(s[i]);
            i++;
            a.push_back(erjin(t));
            numxx++;
            t.clear();
            continue;
        }
        for(int j=i;j<i+num;j++){
            t.push_back(s[j]);
        }
        a.push_back(erjin(t));
        numxx++;
        t.clear();
        i+=num;
        num++;
    }
    cout << numxx << endl;
    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }
    return 0;
}