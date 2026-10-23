int equalDigitFrequency(string s) {
    struct Node {
        int son[10] = {};
        bool counted = false;
    };

    int n = s.size();
    vector<Node> tr(1); // 0 号节点是根，同时用 0 表示没有儿子
    tr.reserve(n * (n + 1) / 2 + 1);

    int ans = 0;

    for (int l = 0; l < n; l++) {
        int cnt[10] = {};
        int kinds = 0, mx = 0;
        int p = 0; // 每个左端点都从根开始

        for (int r = l; r < n; r++) {
            int d = s[r] - '0';

            if (cnt[d] == 0) kinds++;
            cnt[d]++;
            mx = max(mx, cnt[d]);

            // 当前路径表示 s[l..r]
            if (tr[p].son[d] == 0) {
                int id = tr.size();
                tr.emplace_back();
                tr[p].son[d] = id;
            }
            p = tr[p].son[d];

            int len = r - l + 1;
            if (len == kinds * mx && !tr[p].counted) {
                tr[p].counted = true;
                ans++;
            }
        }
    }

    return ans;
}
