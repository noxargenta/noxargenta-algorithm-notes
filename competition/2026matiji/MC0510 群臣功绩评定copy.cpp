#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int dp[205][405][405];
int pre[205][405][405];
vector<int> e[405]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<pair<int, int>> segments(n + 1); 
    vector<int> ls; 

    for (int i = 1; i <= n; i++) {
        cin >> segments[i].first >> segments[i].second;
        ls.push_back(segments[i].first);
        ls.push_back(segments[i].second);
    }

    sort(ls.begin(), ls.end());
    ls.erase(unique(ls.begin(), ls.end()), ls.end());

    int sz = ls.size();

    for (int i = 1; i <= n; i++) {
        int l_idx = lower_bound(ls.begin(), ls.end(), segments[i].first) - ls.begin() + 1;
        int r_idx = lower_bound(ls.begin(), ls.end(), segments[i].second) - ls.begin() + 1;
        e[l_idx].push_back(r_idx);
    }

    for (int i = 0; i <= sz + 1; i++) {
        for (int j = 0; j <= sz + 1; j++) {
            dp[0][i][j] = 1; 
        }
    }
    for (int k = 0; k <= n; k++) {
        for (int l = 0; l <= sz + 1; l++) {
            for (int r = 0; r <= sz + 1; r++) {
                pre[k][l][r] = 1; 
            }
        }
    }

    for (int k = 1; k <= n; k++) {                         
        for (int len = 1; len <= sz; len++) {              
            for (int l = 1; l + len - 1 <= sz; l++) {      
                int r = l + len - 1;                       

                dp[k][l][r] = (dp[k][l][r] + dp[k][l + 1][r]) % MOD;

                for (int p : e[l]) {
                    if (p > r) continue; 

                    if (p == r) {
                        if (k == 1) {
                            dp[k][l][r] = (dp[k][l][r] + 1) % MOD;
                        } else {
                            dp[k][l][r] = (dp[k][l][r] + dp[k - 1][l + 1][r - 1]) % MOD;
                        }
                    } else {
                        long long wayA = 1LL * dp[k - 1][l + 1][p - 1] * pre[k][p + 1][r] % MOD;
                        long long wayB = 1LL * pre[k - 1][l + 1][p - 1] * dp[k][p + 1][r] % MOD;
                        long long overlap = 1LL * dp[k - 1][l + 1][p - 1] * dp[k][p + 1][r] % MOD;

                        dp[k][l][r] = (dp[k][l][r] + wayA) % MOD;
                        dp[k][l][r] = (dp[k][l][r] + wayB) % MOD;
                        dp[k][l][r] = (dp[k][l][r] - overlap + MOD) % MOD; 
                    }
                } 

                pre[k][l][r] = (pre[k - 1][l][r] + dp[k][l][r]) % MOD;
            } 
        } 
    } 

    long long ans = 0; 
    for (int k = 1; k <= n; k++) {
        ans = (ans + 1LL * k * dp[k][1][sz]) % MOD;
    }

    cout << ans << "\n";

    return 0;
}