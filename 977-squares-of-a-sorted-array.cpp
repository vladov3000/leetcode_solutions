#include <span>

class Solution {
public:
    vector<int> sortedSquares(span<const int> numbers) {
        vector<int> result(numbers.begin(), numbers.end());
        for (int& number : result) {
            number *= number;
        }

        sort(result.begin(), result.end());
        return result;
    }
};
