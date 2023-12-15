#include <span>

class Solution {
public:
    string destCity(span<vector<string>> paths) {
        unordered_set<string_view> starts;
        for (vector<string>& path : paths)
            starts.insert(path[0]);

        for (vector<string>& path : paths)
            if (!starts.contains(path[1]))
                return path[1];

        __builtin_unreachable();
    }
};
