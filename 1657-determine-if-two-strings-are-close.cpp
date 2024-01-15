static unordered_map<char, int> count_letters(string_view s) {
    unordered_map<char, int> counts;
    for (char c : s)
        counts[c]++;
    return counts;
}

class Solution {
public:
    bool closeStrings(string_view a, string_view b) {
        unordered_map<char, int> a_counts = count_letters(a);
        unordered_map<char, int> b_counts = count_letters(b);
        for (const auto& [a_c, a_count] : a_counts) {
            bool found = false;
            for (auto& [b_c, b_count] : b_counts) {
                if (a_counts[b_c] > 0 && a_count == b_count) {
                    b_count = 0;
                    found   = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
};
