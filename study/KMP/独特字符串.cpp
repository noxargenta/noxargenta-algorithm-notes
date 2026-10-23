class Solution {
public:
    int equalDigitFrequency(string s) {
        const unsigned long long base = 499;
        unordered_set<unsigned long long> st;

        int n = s.size();

        for (int i = 0; i < n; i++) {
            int cnt[10] = {};
            unsigned long long hashCode = 0;

            int maxCnt = 0;
            int maxCntKinds = 0;
            int allKinds = 0;

            for (int j = i; j < n; j++) {
                int curVal = s[j] - '0';

                // 将当前数字加入子串哈希
                hashCode = hashCode * base + curVal + 1;

                cnt[curVal]++;

                // 第一次出现的数字
                if (cnt[curVal] == 1) {
                    allKinds++;
                }

                // 维护最大频次，以及达到最大频次的数字种数
                if (cnt[curVal] > maxCnt) {
                    maxCnt = cnt[curVal];
                    maxCntKinds = 1;
                } else if (cnt[curVal] == maxCnt) {
                    maxCntKinds++;
                }

                // 所有出现过的数字都达到最大频次
                if (maxCntKinds == allKinds) {
                    st.insert(hashCode);
                }
            }
        }

        return static_cast<int>(st.size());
    }
};
