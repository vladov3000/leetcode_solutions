void helper(
    string_view     digits,
    string&         current,
    vector<string>& result
) {
    if (digits.empty()) {
        result.emplace_back(current);
        return;
    }

    char c      = digits[0];
    char start  = (c - '2') * 3 + 'a' + (c > '7');
    char length = c == '7' || c == '9' ? 4 : 3;
    for (char i = start; i < start + length; i++) {
        current.push_back(i);
        helper(digits.substr(1), current, result);
        current.pop_back();
    }
}

class Solution {
public:
    vector<string> letterCombinations(string_view digits) {
        if (digits.empty())
            return vector<string>();

        string         current;
        vector<string> result;
        helper(digits, current, result);
        return result;
    }
};
