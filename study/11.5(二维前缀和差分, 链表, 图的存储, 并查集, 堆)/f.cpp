#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
vector<int> g[100001];
bool a[10001][10001];
void solve() {
	int n,m ;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
		a[x][y]=1;
		a[y][x]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for(int i=1;i<=n;i++){
		cout << g[i].size() << " ";
		sort(g[i].begin(),g[i].end());
		for(int j=0;j<g[i].size();j++){
			cout << g[i][j] << " ";
		}
		cout << endl;
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