#include <span>

class Solution {
public:
    vector<vector<int>> removeInterval(
        span<vector<int>> intervals, 
        span<int>         removed
    ) {
        vector<vector<int>> result;

        for (const auto& interval : intervals) {
            if (interval[1] < removed[0] || removed[1] < interval[0]) {
                result.emplace_back(interval);
            } else if (removed[0] <= interval[0] && interval[1] <= removed[1]) {
                continue;
            } else {
                if (interval[0] < removed[0] && removed[0] <= interval[1]) {
                    result.emplace_back(initializer_list<int>{ interval[0], removed[0] });
                }
                
                if (interval[0] <= removed[1] && removed[1] < interval[1]) {
                    result.emplace_back(initializer_list<int>{ removed[1], interval[1] });
                }
            }
        }

        return result;
    }
};
