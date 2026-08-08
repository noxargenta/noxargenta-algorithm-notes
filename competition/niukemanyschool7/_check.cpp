#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; if (!(cin >> n)) return 0;
    string dummy; getline(cin, dummy);
    vector<vector<string>> schools(n);
    for (int i = 0; i < n; ++i) {
        string line; getline(cin, line);
        stringstream ss(line); string word;
        while (ss >> word) schools[i].push_back(word);
    }
    vector<int> d(n, 0);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            if (schools[i].size() != schools[j].size()) continue;
            bool same_initials = true;
            for (size_t k = 0; k < schools[i].size(); ++k)
                if (schools[i][k][0] != schools[j][k][0]) { same_initials = false; break; }
            if (same_initials) {
                int p = 0;
                for (size_t k = 0; k < schools[i].size(); ++k)
                    if (schools[i][k] != schools[j][k]) { p = k + 1; break; }
                d[i] = max(d[i], p); d[j] = max(d[j], p);
            }
        }
    for (int i = 0; i < n; ++i) {
        string ans = "";
        for (size_t k = 0; k < schools[i].size(); ++k)
            ans += (k < d[i]) ? schools[i][k] : string(1, schools[i][k][0]);
        cout << ans << "\n";
    }
    return 0;
}
