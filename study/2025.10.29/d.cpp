#include <bits/stdc++.h>
using namespace std;
void solve() {
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    int num = 0;¡°¡±
    auto f = [&](double x) -> double {
        return a*x*x*x + b*x*x + c*x +d;
    };
    for(int i=-10000;i<10000 && num<3;i++){
        double x1=i/100.0;
        double x2=(i+1)/100.0;
        double y1=f(x1);
        double y2=f(x2);
        if(y1*y2<=0){
            if(fabs(y1)<fabs(y2)){
                printf("%.2f ",x1);
                i++;
            }else{
                printf("%.2f ",x2);
                i++;
            }
            num++;
        }
    }
}

signed main() {
    // freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}