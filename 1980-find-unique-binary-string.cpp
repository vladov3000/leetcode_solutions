#include <span>

bool helper(int i, const unordered_set<string_view>& numbers, string& out) {
    if (i == out.size()) {
        return !numbers.contains(out);
    }

    if (helper(i + 1, numbers, out)) {
        return true;
    } else {
        out[i] = '1';
        return helper(i + 1, numbers, out);
    }
}

class Solution {
public:
    /*
    string findDifferentBinaryString(span<string> numbers) {
        string result(numbers.size(), '0');
        unordered_set<string_view> numbers_set(numbers.begin(), numbers.end());
        helper(0, numbers_set, result);
        return result;
    }
    */

     string findDifferentBinaryString(span<string> numbers) {
        if (numbers.size() == 1) {
            return numbers[0][0] == '1' ? "0" : "1";
        }

        int n = numbers.size();
        string result(n, '0');
        unordered_set<string_view> numbers_set(numbers.begin(), numbers.end());

        for (int i = 0; i < n; i++) {
            result[i] = '1';
            if (!numbers_set.contains(result)) {
                return result;
            }
            result[i] = '0';
        }

        result[0] = '1';
        result[1] = '1';
        return result;
     }
};
