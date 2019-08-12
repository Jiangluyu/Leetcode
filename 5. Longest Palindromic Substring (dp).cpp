class Solution {
public:
    string longestPalindrome(string s) {
        int bgIdx = 0;
        int subLen = 1;
        const int sLen = s.size();
        if (sLen <= 1)
            return s;
        bool dp[sLen][sLen];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i < sLen; i++) {
            dp[i][i] = 1;
            dp[i][i-1] = 1;
        }
        for (int j = 2; j <= sLen; j++) {
            for (int k = 0; k <= sLen-j; k++) {
                if (s[k] == s[j+k-1] && dp[k+1][j+k-2]) {
                    // need dp[1][0] == 1 when j == 2
                    dp[k][j+k-1] = 1;
                    if (j > subLen) {
                        bgIdx = k;
                        subLen = j;
                    }
                }
            }
        }
        return s.substr(bgIdx, subLen);
    }
};
