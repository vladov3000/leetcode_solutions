enum Cell {
    SEA = 0,
    LAND = 1,
    NOT_WALKABLE_LAND
};

static void helper(
    vector<vector<int>>& grid, 
    int row, 
    int column
) {
    int n = grid.size();
    int m = grid[0].size();

    if (row < 0 || row >= n || column < 0 || column >= m)
        return;
    
    if (grid[row][column] != LAND)
        return;

    grid[row][column] = NOT_WALKABLE_LAND;
    helper(grid, row - 1, column);
    helper(grid, row, column - 1);
    helper(grid, row + 1, column);
    helper(grid, row, column + 1);
}

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            helper(grid, i, 0);
            helper(grid, i, grid[i].size() - 1);
        }

        for (int i = 0; i < grid[0].size(); i++) {
            helper(grid, 0, i);
            helper(grid, grid.size() - 1, i);
        }

        int result = 0;

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == LAND)
                    result++;

        return result;
    }
};
