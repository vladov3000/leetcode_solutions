// Runtime: 16 ms, faster than 54.89% of C++ online submissions for Palindrome Number.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Palindrome Number.


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x / 10 == 0) return true;
        
        int y = 0;
        int nd = log10(x) + 1;
        while (x / 10 * 10 > y) {
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        if (nd % 2 == 1) y /= 10;
        // cout << x << " " << y;
        return x == y;
    }
};
