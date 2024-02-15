#include <span>

static bool is_palindrome(string_view s) {
    int start = 0;
    int end   = s.size() - 1;
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

class Solution {
public:
    string firstPalindrome(span<string> words) {
        for (const string& word : words) {
            if (is_palindrome(word)) {
                return word;
            }
        }
        return "";
    }
};
