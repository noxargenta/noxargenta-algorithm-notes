#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int x,y;
    x=a-c;
    y=b-d;
    if(x<0){
        x=-x;
    }
    if(y<0){
        y=-y;
    }
    cout << x+y << endl;
}

int main(){
    int _=1;
    cin >> _;
    while(_--){
        solve();
    }
    return 0;
}