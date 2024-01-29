#include <span>

class Solution {
public:
    /* O(3^n) time O(n) space
    int minCost(span<vector<int>> costs, int last_color = -1) {
        if (costs.empty()) {
            return 0;
        }

        int result = INT_MAX;
        for (int i = 0; i < costs[0].size(); i++) {
            if (i != last_color) {
                int cost = minCost(costs.subspan(1), i) + costs[0][i];
                result   = min(result, cost);
            }
        }
        return result;
    }
    */

    // O(n) time O(n) space
    int minCost(span<vector<int>> costs) {
        vector<vector<int>> memoized(3, vector<int>(costs.size()));
        memoized[0][0] = costs[0][0];
        memoized[1][0] = costs[0][1];
        memoized[2][0] = costs[0][2];

        for (int i = 1; i < costs.size(); i++) {
            memoized[0][i] = min(memoized[1][i - 1], memoized[2][i - 1]) + costs[i][0];
            memoized[1][i] = min(memoized[0][i - 1], memoized[2][i - 1]) + costs[i][1];
            memoized[2][i] = min(memoized[0][i - 1], memoized[1][i - 1]) + costs[i][2];
        }

        return min(memoized[0].back(), min(memoized[1].back(), memoized[2].back()));
    }
};
