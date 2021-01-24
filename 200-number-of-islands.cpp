class Solution {
private:
    void dfs(int r, int c, vector<vector<char>>& grid) {
        grid[r][c] = '0';
        
        int dirs[][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        
        for (auto& dir : dirs) {
            int nextR = r + dir[0];
            int nextC = c + dir[1];
            
            if (nextR < 0 || nextR > grid.size() - 1) {
                continue;
            }
            
            if (nextC < 0 || nextC > grid[0].size() - 1) {
                continue;
            }
            
            if (grid[nextR][nextC] == '0') {
                continue;
            }
            
            dfs(nextR, nextC, grid);
        }
        
        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        
        int res = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                
                dfs(i, j, grid);
                
                res++;
            }
        } 
        
        return res;
    }
};
