#include <span>

class Solution {
public:
    bool containsDuplicate(span<int> numbers) {
        unordered_set<int> seen(numbers.begin(), numbers.end());
        return seen.size() != numbers.size();
    }
};
