class Solution {
public:
    int longestCommonSubsequence(string_view a, string_view b) {
        vector<vector<int>> memoized(a.size(), vector<int>(b.size()));
        memoized[0][0] = a[0] == b[0];
        
        bool matched = false;
        for (int i = 0; i < a.size(); i++) {
            matched        = matched || a[i] == b[0];
            memoized[i][0] = matched;
        }

        matched = false;
        for (int i = 0; i < b.size(); i++) {
            matched        = matched || a[0] == b[i];
            memoized[0][i] = matched;
        }

        for (int i = 1; i < memoized.size(); i++) {
            for (int j = 1; j < memoized[i].size(); j++) {
                if (a[i] == b[j]) {
                    memoized[i][j] = memoized[i - 1][j - 1] + 1;
                } else {
                    memoized[i][j] = max(memoized[i - 1][j], memoized[i][j - 1]);
                }
            }
        }

        return memoized[a.size() - 1][b.size() - 1];
    }
};
