#include <span>

class Solution {
public:
    int lengthOfLIS(span<int> numbers) {
        vector<int> subsequence;
        subsequence.push_back(numbers[0]);

        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] > subsequence.back()) {
                subsequence.push_back(numbers[i]);
            } else {
                auto larger = lower_bound(
                    subsequence.begin(), subsequence.end(), numbers[i]
                );
                *larger = numbers[i];
            }
        }

        return subsequence.size();
    }
};
