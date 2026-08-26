#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define ll long long
const double PI=M_PI;
double getoq(double r,double os,ll sy,double theta,double thetas){
    return r*os*abs(sin(theta-thetas))*1.0/sy;
}
void solve() {
    ll sx,sy,ax,ay,bx,by;
    cin >> sx>>sy>>ax>>ay>>bx>>by;
    double r=hypot(ax,ay);
    double os=hypot(sx,sy);
    double theta=atan2(sy,sx);
    double thetaa=atan2(ay,ax);
    double thetab=atan2(by,bx);
    double minans=LLONG_MAX;
    double maxans=-LLONG_MAX;
    if(theta>=thetaa && theta <= thetab){
        minans=0;
    }else {
        minans=min(getoq(r,os,sy,thetaa,theta),getoq(r,os,sy,thetab,theta));
    }
    maxans=max(getoq(r,os,sy,thetaa,theta),getoq(r,os,sy,thetab,theta));
    double t1=theta + PI/2.0,t2=theta - PI/2.0;

    if(t1>=thetaa && t1<= thetab){
        maxans=max(maxans,getoq(r,os,sy,t1,theta));
    }
    if(t2>=thetaa && t2<= thetab){
        maxans=max(maxans,getoq(r,os,sy,t2,theta));
    }
    cout << fixed << setprecision(15) ;
    cout << minans << " " << maxans <<endl;
}

signed main() {
//  freopen("../data/data.in","r",stdin), freopen("../data/data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}