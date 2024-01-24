#include <span>

class Solution {
public:
    // O(n^2) time, O(n) space
    int maxLength(span<string> strings) {
        vector<bitset<26>> memoized(1);
        int                result = 0;

        for (string_view string : strings) {
            bitset<26> new_letters;
            for (char c : string) {
                new_letters.set(c - 'a');
            }

            if (new_letters.count() < string.size()) {
                continue;
            }

            for (int i = memoized.size() - 1; i >= 0; i--) {
                bitset<26> old_letters = memoized[i];
                if ((old_letters & new_letters).any()) {
                    continue;
                }

                memoized.emplace_back(old_letters | new_letters);
                result = max(result, (int) (old_letters.count() + new_letters.count()));
            }
        }

        return result;
    }
};
