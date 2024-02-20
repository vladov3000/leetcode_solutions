#include <span>

class Solution {
public:
    int maxSubArray(span<int> numbers) {
        int current = numbers[0];
        int result  = numbers[0];
        for (int i = 1; i < numbers.size(); i++) {
            current = max(current + numbers[i], numbers[i]);
            result  = max(result, current);
        }
        return result;
    }
};
