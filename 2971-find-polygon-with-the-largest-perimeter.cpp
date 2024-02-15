#include <span>

class Solution {
public:
    long largestPerimeter(span<int> numbers) {
        sort(numbers.begin(), numbers.end());

        long result = -1;
        long sum    = numbers[0] + numbers[1];
        for (int i = 2; i < numbers.size(); i++) {
            if (sum > numbers[i]) {
                result = max(result, static_cast<long>(sum + numbers[i]));
            }
            sum += numbers[i];
        }
        return result;
    }
};
