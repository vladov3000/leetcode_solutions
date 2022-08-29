class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                result += dfs(grid, i, j);
        return result;
    }
    
private:
    int dfs(vector<vector<char>>& grid, int i, int j) {
        if (i == -1 || i == grid.size() || 
            j == -1 || j == grid[i].size() ||
            grid[i][j] == '0')
            return 0;
       
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        
        return 1;
    }
};
