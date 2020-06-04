// Runtime: 40 ms, faster than 97.78% of C++ online submissions for Reverse String.
// Memory Usage: 23.3 MB, less than 6.10% of C++ online submissions for Reverse String.

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() < 2) return;
        for (int i=0; i < s.size() / 2; i++) {
            swap(s[i], s[s.size()-1-i]);
        }
        // reverse(s.begin(), s.end());
    }
};
