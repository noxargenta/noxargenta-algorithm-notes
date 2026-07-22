#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n+1);
    for(int i=0;i<=n-1;i++){
        a[i+1]=s[i]-'0';
    }
    int l,r;
    l=-1;r=-1;
    int maxx=-0x7f7f7f7f;
    int ok=0;
    for(int mid=1;mid<=n;mid++){
        if(a[mid]==0){
            ok=1;
            l=mid;
            r=mid;
            while((l>1 && a[l]==0)|| (a[l]==1 && l!=1 && a[l-1]==1)){
                l--;
            }
            while((r<n && a[r]==0)||(a[r]==1 && r!=n && a[r+1]==1)){
                r++;
            }
            maxx=max(maxx,r-l+1);
            mid=r;
        }
    }
    if(ok==0){
        maxx=n;
    }
    cout << maxx << endl;
}
int main(){
    int _=1;
    cin >> _;
    while(_--){
        solve();
    }
    return 0;
}