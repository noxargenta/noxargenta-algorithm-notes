#include <bits/stdc++.h>
using namespace std;

int n, m;
int need;
vector<vector<int>> a;
int cnt[3];

long long solutionCount = 0;
vector<vector<int>> firstAnswer;

// 八个方向
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// 检查三个数字是否分别八连通
bool checkConnected() {
    for (int color = 0; color < 3; color++) {
        pair<int, int> start = {-1, -1};

        // 找到这个数字的第一个格子
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == color) {
                    start = {i, j};
                    break;
                }
            }
            if (start.first != -1) break;
        }

        if (start.first == -1) return false;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        q.push(start);
        vis[start.first][start.second] = true;

        int reached = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            reached++;

            for (int k = 0; k < 8; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }

                if (!vis[nx][ny] && a[nx][ny] == color) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        // 统计这个数字实际出现了多少个格子
        int total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == color) {
                    total++;
                }
            }
        }

        if (reached != total) {
            return false;
        }
    }

    return true;
}

// 检查当前位置填入 color 后，是否出现连续三个相同数字
bool canPlace(int pos, int color) {
    int x = pos / m;
    int y = pos % m;

    // 横向检查：当前位置、左边两个
    if (y >= 2 &&
        a[x][y - 1] == color &&
        a[x][y - 2] == color) {
        return false;
    }

    // 纵向检查：当前位置、上面两个
    if (x >= 2 &&
        a[x - 1][y] == color &&
        a[x - 2][y] == color) {
        return false;
    }

    return true;
}

void dfs(int pos) {
    if (pos == n * m) {
        if (checkConnected()) {
            solutionCount++;

            if (firstAnswer.empty()) {
                firstAnswer = a;
            }
        }
        return;
    }

    int x = pos / m;
    int y = pos % m;

    for (int color = 0; color < 3; color++) {
        // 每种数字不能超过要求数量
        if (cnt[color] >= need) {
            continue;
        }

        // 提前剪枝：当前位置不能造成三个连续相同数字
        if (!canPlace(pos, color)) {
            continue;
        }

        a[x][y] = color;
        cnt[color]++;

        dfs(pos + 1);

        cnt[color]--;
        a[x][y] = -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    if ((n * m) % 3 != 0) {
        cout << "nm 不能被 3 整除\n";
        return 0;
    }

    need = n * m / 3;

    a.assign(n, vector<int>(m, -1));
    memset(cnt, 0, sizeof(cnt));

    dfs(0);

    cout << "合法方案数量: " << solutionCount << "\n";

    if (solutionCount == 0) {
        cout << "No\n";
        return 0;
    }

    cout << "第一组合法方案:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << firstAnswer[i][j];
        }
        cout << '\n';
    }

    return 0;
}
