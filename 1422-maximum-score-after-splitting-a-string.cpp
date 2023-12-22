class Solution {
public:
    int maxScore(string_view s) {
        int right  = count(s.cbegin(), s.cend(), '1');
        int left   = 0;
        int result = 0;

        for (char c : s.substr(0, s.size() - 1)) {
            left  += c == '0';
            right -= c == '1';
            result = max(result, right + left);
        }

        return result;
    }
};
