static unordered_map<char, int> get_counts(string_view s) {
    unordered_map<char, int> result;
    for (char c : s) {
        result[c]++;
    }
    return result;
}

class Solution {
public:
    int minSteps(string_view s, string_view t) {
        unordered_map<char, int> s_counts = get_counts(s);
        unordered_map<char, int> t_counts = get_counts(t);

        int result = 0;
        for (const auto& [c, s_count] : s_counts) {
            int t_count = t_counts[c];
            if (s_count > t_count) {
                result += s_count - t_count;
            }
        }
        return result;
    }
};
