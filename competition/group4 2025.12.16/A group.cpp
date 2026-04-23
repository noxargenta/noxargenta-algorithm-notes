#include <bits/stdc++.h>
using namespace std;
//sukiyu
#define int long long
#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
    int n;
    cin >> n;
    map<int, int> head;
    vector<int> arr(n + 1), bi(n + 1);
    auto Find = [&] (int x, auto&& fale) -> int {
        if (bi[x] == x) {
            return x;
        }
        return bi[x] = fale(bi[x], fale);
    };
    auto he = [&] (int a, int b) -> int {
        int aa = Find(a, Find);
        int bb = Find(b, Find);
        if (aa != bb) {
            bi[aa] = bb;
        } 
        return 1;
    };
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        head[i] ++;
        head[arr[i]] ++;
        bi[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        he(i, arr[i]);
    }
    int cnt = 0;
    map<int, int> mp;
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        if (!mp.count(Find(i, Find))) {
            ret.push_back(Find(i, Find));
            mp[Find(i, Find)]++;
            cnt ++;
        } else {
            mp[Find(i, Find)]++;
        }
    }
    int r = 0;
    for (auto j : ret) {
        int now = Find(j, Find);
        bool ok = false;
        int l = 0;
        for (int i = 1; i <= n; i++) {
            if (now == Find(i, Find)) {
                if (head[i] == 1) {
                    ok = true;
                }
                l ++;
            }
        }
        if (ok || l == 2) {
            r ++;
        }
    }

    cout << cnt - r + (r != 0) << ' ' << cnt << endl;

}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >>  _;
    while (_ --) {
        solve();
    }
}
/*
				 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
			 __.'              ~.   .~              `.__
		   .'//   A    C    之   \./  之    真    理  \`.
		 .'//                     |                     \`.
	   .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
	 .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.
*/