class Solution {
public:
    string customSortString(string_view order, string_view s) {
        unordered_map<char, int> priority;
        for (int i = 0; i < order.size(); i++) {
            priority[order[i]] = i;
        }

        string result(s.begin(), s.end());
        sort(result.begin(), result.end(), [&](char a, char b) {
            return priority[a] < priority[b];
        });

        return result;
    }
};
