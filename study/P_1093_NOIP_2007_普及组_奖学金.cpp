#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
struct Student{
    int chinese;
    int math;
    int eng;
    int sum;
    int id;
};
void solve() {
    int n;
    cin >> n;
    vector<Student> s(n+1);
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin >> a >> b  >> c;
        s[i].chinese=a;
        s[i].math=b;
        s[i].eng=c;
        s[i].sum=a+b+c;
        s[i].id=i;
    }
    sort(s.begin()+1,s.end(),[&](Student x , Student y){
        if(x.sum!=y.sum){
            return x.sum>y.sum;
        }else if(x.chinese!=y.chinese){
            return x.chinese>y.chinese;
        }else {
            return x.id<y.id;
        }
    });
    for(int i=1;i<=5;i++){
        cout << s[i].id << ' ' << s[i].sum << endl;
    }
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