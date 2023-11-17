#include <span>

class Solution {
public:
    int minPairSum(span<int> numbers) {
        sort(numbers.begin(), numbers.end());
        int result = 0;

        for (int i = 0; i < numbers.size() / 2; i++) {
            result = max(result, numbers[i] + numbers[numbers.size() - 1 - i]);
        }

        return result;
    }
};
