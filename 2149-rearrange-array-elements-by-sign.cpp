#include <span>

class Solution {
public:
    vector<int> rearrangeArray(span<int> numbers) {
        vector<int> result(numbers.size());

        int positive = 0;
        int negative = 1;

        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] > 0) {
                result[positive] = numbers[i];
                positive += 2;
            } else if (numbers[i] < 0) {
                result[negative] = numbers[i];
                negative += 2;
            }
        }

        return result;
    }
};
