#include <span>

class Solution {
public:
    bool makeEqual(span<string> words) {
        array<int, 26> counts = {};
        for (string_view word : words)
            for (char c : word)
                counts[c - 'a']++;
        for (int count : counts)
            if (count % words.size() != 0)
                return false;
        return true;
    }
};
