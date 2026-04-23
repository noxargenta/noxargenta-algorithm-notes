#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
#define int long long
void solve() {
	int n,k;
	cin >> n>>k;
	bool ok=0;
	vector<int> a;
	if(n-(k-1)*1 >0 && (n-(k-1)*1)%2==1){
		ok=1;
		a.push_back(n-(k-1)*1);
		k--;
		while(k--){
			a.push_back(1);
		}
	}else if(n-(k-1)*2>0 && (n-(k-1)*2)%2==0){
		ok=1;
		a.push_back(n-(k-1)*2);
		k--;
		while(k--){
			a.push_back(2);
		}
	}
	if(ok){
		cout << "yes\n";
		for(auto x : a){
			cout << x << ' '; 
		}
		cout << endl;
	}else {
		cout << "no\n";
	}
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