#include <span>

class Solution {
public:
    int maxSumAfterPartitioning(span<int> array, int k) {
        vector<int> memoized(array.size() + 1);
        memoized[0] = 0;
        for (int i = 1; i <= array.size(); i++) {
            int largest = 0;
            for (int j = 1; j <= k; j++) {
                if (i - j < 0) {
                    break;
                }
                largest     = max(largest, array[i - j]);
                memoized[i] = max(memoized[i], memoized[i - j] + largest * j);
            }
        }
        return memoized.back();
    }
};
