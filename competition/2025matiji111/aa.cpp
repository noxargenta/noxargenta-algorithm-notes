#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve(){
    string s;
    string t;
    cin >> s >> t;
    int l=0;
    int r=s.length()-1;
    bool lx=0,rx=0;
    for(int i=0;i<s.length();i++){
        if(lx==1){
            break;
        }
        if(s[i]!=t[i]){
            lx=1;
            l=i;
        }
    }
    for(int i=s.length();i>=0;i--){
        if(rx==1){
            break;
        }
        if(s[i]!=t[i]){
            rx=1;
            r=i;
        }
    }
    //cout << l << " " << r << endl << lx <<' ' << rx << endl;
    bool ok=1;
    if(rx==1 && lx==1){
        reverse(s.begin()+l,s.begin()+r+1);
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]){
                ok=0;
                break;
            }
        }
    }
    //cout << s << endl << t << endl;
    if(ok==1){
        cout << "Y\n";
    }else {
        cout << "N\n";
    }

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _=1;
    cin >> _;
    while(_--){
        solve();
    }
    return 0;
}