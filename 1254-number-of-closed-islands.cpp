static void clear_island(
    vector<vector<int>>& grid, 
    int row, 
    int column
) {
    int n = grid.size();
    int m = grid[0].size();

    if (row < 0 || row >= n || column < 0 || column >= m)
        return;

    if (grid[row][column] != 0)
        return;
    
    grid[row][column] = 1;
    clear_island(grid, row - 1, column);
    clear_island(grid, row + 1, column);
    clear_island(grid, row, column - 1);
    clear_island(grid, row, column + 1);
}

static bool is_island(
    vector<vector<int>>& grid, 
    int row, 
    int column
) {
    if (grid[row][column] != 0)
        return false;

    clear_island(grid, row, column);
    return true;
}

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            clear_island(grid, i, 0);
            clear_island(grid, i, grid[i].size() - 1);
        }

        for (int i = 0; i < grid[0].size(); i++) {
            clear_island(grid, 0, i);
            clear_island(grid, grid.size() - 1, i);
        }

        int result = 0;

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (is_island(grid, i, j))
                    result++;

        return result;
    }
};
