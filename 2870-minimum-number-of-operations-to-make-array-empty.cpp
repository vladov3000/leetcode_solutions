#include <span>

class Solution {
public:
    int minOperations(span<int> numbers) {
        unordered_map<int, int> counts;
        for (int number : numbers)
            counts[number]++;

        int result = 0;
        for (const auto& [number, count] : counts) {
            if (count == 1)
                return -1;
            else if (count % 3 == 0)
                result += count / 3;
            else
                result += count / 3 + 1;
        }
        return result;
    }
};
