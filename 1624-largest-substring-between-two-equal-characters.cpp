class Solution {
public:
    int maxLengthBetweenEqualCharacters(string_view s) {
        int result     = -1;
        int starts[26] = {};

        for (int i = 0; i < s.size(); i++) {
            char c = s[i] - 'a';
            if (starts[c] == 0)
                starts[c] = i + 1;
            else
                result = max(result, i - starts[c]);
        }

        return result;
    }
};
