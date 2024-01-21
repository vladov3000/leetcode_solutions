#include <span>

class Solution {
public:
    // O(2^n) runtime O(n) memory
    /*
    int rob(span<int> numbers) {
        if (numbers.size() == 0) {
            return 0;
        }

        if (numbers.size() == 1) {
            return numbers[0];
        }

        int previous = rob(numbers.subspan(0, numbers.size() - 1));
        int skipped  = rob(numbers.subspan(0, numbers.size() - 2)) + numbers.back();
        return max(previous, skipped);
    }
    */

    // O(n) runtime, O(n) memory
    int rob(span<int> numbers) {
        if (numbers.size() == 1) {
            return numbers[0];
        }

        vector<int> memoized(numbers.size());
        memoized[0] = numbers[0];
        memoized[1] = max(numbers[0], numbers[1]);

        for (int i = 2; i < numbers.size(); i++) {
            memoized[i] = max(memoized[i - 1], memoized[i - 2] + numbers[i]);
        }

        return memoized.back();
    }
};
