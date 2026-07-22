#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define mod 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	ll n, l = 0, r = INFLL, cnt = 0, ans = 0;
	cin >> n;
	vector<ll> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		r = min(r, a[i] + b[i]);
		ans += a[i] + b[i];
	}
	auto check = [&](ll m)->bool{
		vector<ll> arr = a;
		for(int i=1;i<=n;i++){
			if(arr[i]+b[i]<m||arr[i]<arr[i-1]) return 0;
			arr[i]=max(arr[i-1],m-b[i]);
			if(arr[i]>m) return 0;
		}
		return 1;
	};
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			cnt = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << ans - n *cnt << endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}