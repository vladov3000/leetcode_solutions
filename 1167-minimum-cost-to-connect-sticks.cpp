#include <span>

class Solution {
public:
    int connectSticks(span<int> sticks) {
        multiset<int> sorted(sticks.begin(), sticks.end());

        int result = 0;
        while (sorted.size() > 1) {
            auto a = sorted.cbegin();
            auto b = ++sorted.cbegin();
            result += *a + *b;
            sorted.insert(*a + *b);
            sorted.erase(a);
            sorted.erase(b);
        }

        return result;
    }
};
