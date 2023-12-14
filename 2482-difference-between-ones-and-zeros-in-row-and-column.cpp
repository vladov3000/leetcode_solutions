#include <span>

class Solution {
public:
    vector<vector<int>> onesMinusZeros(span<vector<int>> grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> row_deltas(n);
        vector<int> column_deltas(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int delta = grid[i][j] == 0 ? -1 : 1;
                row_deltas[i] += delta;
                column_deltas[j] += delta;
            }
        }

        vector<vector<int>> result(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                result[i][j] = row_deltas[i] + column_deltas[j];
        return result;
    }
};
