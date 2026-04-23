#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> r,e;

    for(int i=0;i<s.length();i++){
        if(s[i]=='r'){
            r.push_back(i);
        }else if(s[i]=='e'){
            e.push_back(i);
        }
    }
    int res=0;
    for(int i=0;i<r.size();i++){
        for(int j=0;j<e.size();j++){
            bool ok=1;
            if(i>j){
                for(int k=i;k<=j;k++){
                    if(s[k]=='d'){
                        ok=0;
                        break;
                    }
                }
                if(ok==1){
                    int zuo=0;
                    int you=0;
                    int i1=i,j1=j;
                    for(;s[i1]!='d';i1--){
                        zuo++;
                    }
                    for(;s[j1]!='d';j1++){
                        you++;
                    }
                    res+=((zuo+1)*(you+1));
                }else {
                    ok=1;
                }
            }else {
                for(int k=j;k<=i;k++){
                    if(s[k]=='d'){
                        ok=0;
                        break;
                    }
                }
                if(ok==1){
                    res++;
                }else {
                    ok=1;
                }
            }
        }
    }
    cout << res;
    return 0;
}
