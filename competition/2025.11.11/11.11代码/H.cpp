/**EditTime: 2025-04-30 20:55**/

#include <bits/stdc++.h>
using namespace std;

template<class T> using vt = vector<T>;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define fread freopen("data.in", "r", stdin), freopen("data.out", "w", stdout)
#define mst(x, y) memset(x, y, sizeof x)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define bitset(x) ((x) & (-x))
#define int long long

typedef pair<int, int> pii;

const int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int N = 1e3 + 10;

int res[2 * N];
bool vis[2 * N];

void solve() {
	int n;
	cin >> n;
	int x = 0;
	mst(vis, false);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			cin >> x, res[i + j] = x, vis[x] = true;

	for (int i = 1; i <= 2 * n; i ++)
		if (!vis[i])
			res[1] = i;

	for (int i = 1; i <= 2 * n; i ++)
		cout << res[i] << " ";
	cout << endl;
}

signed main() {
//	fread;
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t --)
		solve();
}