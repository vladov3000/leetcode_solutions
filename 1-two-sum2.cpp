#include <span>

class Solution {
public:
    vector<int> twoSum(span<int> numbers, int target) {
        unordered_map<int, int> needed_to_index;
        for (int i = 0; i < numbers.size(); i++) {
            needed_to_index[target - numbers[i]] = i;
        }

        for (int i = 0; i < numbers.size(); i++) {
            const auto result = needed_to_index.find(numbers[i]);
            if (result != needed_to_index.cend() && i != result->second) {
                return initializer_list<int> { i, result->second };
            }
        }

        __builtin_unreachable();
    }
};
