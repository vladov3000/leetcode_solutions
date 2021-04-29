impl Solution {
    pub fn unique_paths_with_obstacles(mut grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        
        if grid[0][0] == 1 {
            return 0;
        }
        grid[0][0] = 1;
        
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 && !(i == 0 && j == 0) {
                    grid[i][j] = 0;
                } else {
                    if i > 0 {
                        grid[i][j] += grid[i - 1][j];
                    }
                    if j > 0 {
                        grid[i][j] += grid[i][j - 1];
                    }
                }
            }
        }
        
        return grid[m - 1][n - 1];
    }
}
