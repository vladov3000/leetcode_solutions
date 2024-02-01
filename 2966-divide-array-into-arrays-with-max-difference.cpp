#include <span>

static int max_diff(span<int> as) {
    int result = INT_MIN;
    for (int i = 0; i < as.size(); i++) {
        for (int j = 0; j < as.size(); j++) {
            result = max(result, abs(as[i] - as[j]));
        }
    }
    return result;
}

class Solution {
public:
    vector<vector<int>> divideArray(span<int> as, int k) {
        sort(as.begin(), as.end());

        vector<vector<int>> result;
        for (int i = 0; i < as.size(); i += 3) {
            span<int> current = as.subspan(i, 3);
            if (max_diff(current) > k) {
                return vector<vector<int>>();
            }
            result.emplace_back(current.begin(), current.end());
        }
        return result;
    }
};
