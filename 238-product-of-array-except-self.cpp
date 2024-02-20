#include <span>

class Solution {
public:
    vector<int> productExceptSelf(span<int> numbers) {
        vector<int> lefts(numbers.begin(), numbers.end());
        partial_sum(lefts.begin(), lefts.end(), lefts.begin(), multiplies());

        vector<int> rights(numbers.begin(), numbers.end());
        partial_sum(rights.rbegin(), rights.rend(), rights.rbegin(), multiplies());

        vector<int> result(numbers.size());
        for (int i = 0; i < result.size(); i++) {
            int left  = i == 0                 ? 1 : lefts[i - 1];
            int right = i == result.size() - 1 ? 1 : rights[i + 1];
            result[i] = left * right;
        }
        return result;
    }
};
