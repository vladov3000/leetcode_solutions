class Solution {
public:
    /*
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }

        int result = INT_MAX;
        for (int i = 1; i <= sqrt(n); i++) {
            result = min(result, numSquares(n - i * i));
        }
        return result + 1;
    }
    */

    int numSquares(int n) {
        vector<int> memoized(n + 1, INT_MAX);
        memoized[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                memoized[i] = min(memoized[i], memoized[i - j * j] + 1);
            }
        }
        
        return memoized.back();
    }
};
