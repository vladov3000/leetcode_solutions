class Solution {
public:
    int firstUniqChar(string_view s) {
        unordered_map<char, int> frequencies;
        for (char c : s) {
            frequencies[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (frequencies[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
