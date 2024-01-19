#include <span>

class Solution {
public:
    int minFallingPathSum(span<vector<int>> matrix) {
        for (int i = matrix.size() - 2; i >= 0; i--) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int below     = matrix[i + 1][j];
                int left      = j == 0 ? INT_MAX : matrix[i + 1][j - 1];
                int right     = j == matrix[i].size() - 1 ? INT_MAX : matrix[i + 1][j + 1];
                matrix[i][j] += min(below, min(left, right));
            }
        }
        return *min_element(matrix[0].cbegin(), matrix[0].cend());
    }
};
