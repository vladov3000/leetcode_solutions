class Solution {
public:
    int climbStairs(int n) {
        int memoized[] = { 1, 1 };
        int result     = 1;
        for (int i = 2; i <= n; i++) {
            result      = memoized[1] + memoized[0];
            memoized[0] = memoized[1];
            memoized[1] = result;
        }
        return result;
    }
};
