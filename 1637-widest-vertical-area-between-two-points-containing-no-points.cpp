#include <span>

class Solution {
public:
    int maxWidthOfVerticalArea(span<vector<int>> points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int result = 0;
        for (int i = 1; i < points.size(); i++) {
            result = max(result, points[i][0] - points[i - 1][0]);
        }
        return result;
    }
};
