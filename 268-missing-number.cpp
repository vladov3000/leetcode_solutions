#include <span>

class Solution {
public:
    int missingNumber(span<const int> numbers) {
        int n = numbers.size();
        return n * (n + 1) / 2 - reduce(numbers.begin(), numbers.end());
    }
};
