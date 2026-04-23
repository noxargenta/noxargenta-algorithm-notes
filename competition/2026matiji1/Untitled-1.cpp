// #include <bits/stdc++.h>
// #define int long long
// #define endl '\n'
// using namespace std;
// struct a{
//     int id;
//     int sum;
// };
// bool cmp(a x,a y){
//     if(x.sum!=y.sum){
//         return x.sum>y.sum;
//     }else return x.id<y.id;
// }
// void solve(){
//     // vector<struct a> b(4);
//     // for(int i=1;i<=3;i++){
//     //     cin >> b[i].id >> b[i].sum;
//     // }
//     // sort(b.begin()+1,b.end(),[&](const a &i,const a &j){
//     //     return i.sum<j.sum;
//     // });
//     // for(int i=1;i<=3;i++){
//     //     cout << b[i].sum << endl;
//     // }
//     int pos1=lower_bound(a.begin(),a.end(),4)-a.begin();
//     string s = "lanqiao";
//     string sub = s.substr(3, 4); // 从下标3开始，截取长度为4的串 -> "qiao"
//     int pos = s.find("qia");     // 查找子串，找到返回首字母下标，找不到返回 string::npos
//     int pos=s.find("lan");
//     if(pos==string::npos){
//         cout << -1 << endl;
//     }
//     ll lcm = (ll)a / __gcd(a, b) * b; 
//     int fast_mi(int a,int b ,int p){
//         int ans=1;
//         a%=p;
//         while(b>0){
//             if((b&1)==1)
//                 ans=(ans*a)%p;
//             a=(a*a)%p;
//             b>>=1;
//         }
//         return ans;
//     }
// }
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int _=1;
//     //cin >> _;
//     while(_--){
//         solve();
//     }
// }
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
    cout << atan2(666.0,233.0);
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