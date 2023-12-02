#include <span>

array<int, 26> count(string_view s) {
    array<int, 26> result = {};
    for (char c : s)
        result[c - 'a']++;
    return result;
}

bool formable(const array<int, 26>& source, const array<int, 26>& destination) {
    for (int i = 0; i < 26; i++)
        if (source[i] < destination[i])
            return false;
    return true;
}

class Solution {
public:
    int countCharacters(span<string> words, string_view chars) {
        int result = 0;

        for (string_view word : words)
            if (formable(count(chars), count(word)))
                result += word.size();

        return result;
    }
};
