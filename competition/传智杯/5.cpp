#include <bits/stdc++.h>
using namespace std;
struct yao
{
    int teng;
    int xiao;
};
int main() {
    int n;
    cin >> n;
    vector<yao> a(n);
    while(n--){
        cin >> a[n].teng >> a[n].xiao;
    }
    sort(a.begin(),a.end(),[&](int ,int y){
        return a[x].teng<a[y].teng;
    });
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        int res=-1;
        for(int i=0;i<a.size();i++){
            if(a[i].teng>t){
                break;
            }
            if(a[i].teng<=t){
                res=max(res,a[i].xiao);
            }
        }
        cout << res << endl;
    }
}
