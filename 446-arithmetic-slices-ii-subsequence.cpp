#include <span>

class Solution {
public:
    int numberOfArithmeticSlices(span<int> numbers) {
        int                              result = 0;
        vector<unordered_map<long, int>> index_to_deltas(numbers.size());
        for (int i = 1; i < numbers.size(); i++) {
            for (int j = 0; j < i; j++) {
                long       delta = static_cast<long>(numbers[j]) - numbers[i];
                const auto entry = index_to_deltas[j].find(delta);
                index_to_deltas[i][delta]++;
                if (entry != index_to_deltas[j].cend()) {
                    index_to_deltas[i][delta] += index_to_deltas[j][delta];
                    result                    += index_to_deltas[j][delta];
                }
            }
        }
        return result;
    }
};
