class Solution {
public:
    int minDistance(string_view word1, string_view word2) {
        int n = word1.size();
        int m = word2.size();

        static int dp[501][501];
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++)
            dp[i][0] = dp[i - 1][0] + 1;

        for (int i = 1; i <= m; i++)
            dp[0][i] = dp[0][i - 1] + 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }

                int insert = dp[i - 1][j];
                int remove = dp[i][j - 1];
                int replace = dp[i - 1][j - 1];
                dp[i][j] = min(insert, min(remove, replace)) + 1;
            }
        }

        return dp[n][m];
    }
};
