#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,x,y;
    cin >> n >> x >> y;
    vector<long long> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for(long long l=0;l<n;l++){
        if (a[l] == 0) {
            continue;
        }
        long long x2=x/a[l];
        if (x2 == 0){
            continue;
        }
        long long maijin=x2*a[l];
        for(long long r=l+1;r<n;r++){
            long long maichu=x2*a[r];
            if(maichu - maijin==y){
                cout << l + 1 << " " << r + 1 << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
