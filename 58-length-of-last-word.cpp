class Solution {
public:
    int lengthOfLastWord(string_view s) {
        while (s.back() == ' ') {
            s = s.substr(0, s.size() - 1);
        }

        int result = 0;
        while (result < s.size()) {
            if (s[s.size() - result - 1] == ' ') {
                break;
            }
            result++;
        }
        return result;
    }
};
