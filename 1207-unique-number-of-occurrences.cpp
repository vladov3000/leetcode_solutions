#include <span>

class Solution {
public:
    bool uniqueOccurrences(span<int> numbers) {
        unordered_map<int, int> counts;
        for (int number : numbers) {
            counts[number]++;
        }

        unordered_set<int> seen;
        for (const auto [number, count] : counts) {
            if (seen.contains(count)) {
                return false;
            }
            seen.insert(count);
        }
        return true;
    }
};
