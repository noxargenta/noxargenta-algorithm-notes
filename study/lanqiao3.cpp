#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
bool ifrunnian(int year){
    if((year % 4 == 0  && year %100 != 0 ) || year % 400 == 0 ){
        return 1;
    }else {
        return 0;
    }
}
void solve() {
    int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int year=2000,month=1,day=1;
    int week=6;
    int sum=0;
    while(true){
        if(ifrunnian(year)){
            months[2]=29;
        }else {
            months[2]=28;
        }
        if(week==1 || day==1){
            sum+=2;
        }else {
            sum+=1;
        }
        if(year==2020 && month==10 && day==1  ){
            break;
        }
        day++;
        if(day>months[month]){
            day=1;
            month++;
            if(month>12){
                year++;
                month=1;
            }
        }
        week=(week%7)+1;
    }
    cout << sum << endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}