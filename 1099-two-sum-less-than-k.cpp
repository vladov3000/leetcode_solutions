#include <span>

class Solution {
public:
    int twoSumLessThanK(span<int> numbers, int k) {
        sort(numbers.begin(), numbers.end());

        int result = -1;
        int start  = 0;
        int end    = numbers.size() - 1;

        while (start != end) {
            if (numbers[start] + numbers[end] >= k) {
                end--;
            } else {
                result = max(result, numbers[start] + numbers[end]);
                start++;
            }
        }

        return result;
    }
};
