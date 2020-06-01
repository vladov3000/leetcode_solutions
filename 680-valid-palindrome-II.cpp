// Runtime: 184 ms, faster than 57.05% of C++ online submissions for Valid Palindrome II.
// Memory Usage: 24 MB, less than 36.36% of C++ online submissions for Valid Palindrome II.

class Solution {
private:
    bool helper(string s, int a, int b) {
        while (a < b) {
            if (s[a++] != s[b--]) return false;
        }
        
        return true;
    }
public:
    bool validPalindrome(string s) {
        if (s.size() < 2) return true;
        
        int a = 0;
        int b = s.size() - 1;
        while (a < b) {
            if (s[a++] != s[b--]) {
                return helper(s, a-1, b) || helper(s, a, b+1);
            }
        }
        return true;
    }
};
