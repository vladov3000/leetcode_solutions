class Solution {
    private int getVal(char[][] matrix, int i, int j) {
        return matrix[i][j] == '1' ? 1 : 0;
    }
    
    public int maximalSquare(char[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;   
            
        int[][] dp = new int[m][n];
        
        dp[0][0] = getVal(matrix, 0, 0);
        for (int i = 1; i < m; i++) {
            dp[i][0] = getVal(matrix, i, 0);
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = getVal(matrix, 0, j);
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = getVal(matrix, i, j);
                if (dp[i][j] > 0) {
                    int prev = Math.min(dp[i-1][j], dp[i][j-1]);
                    prev = Math.min(prev, dp[i-1][j-1]);
                    dp[i][j] += prev;
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = Math.max(res, dp[i][j]);
            }
        }
        
        // for (int i = 0; i < dp.length; i++) System.out.println(Arrays.toString(dp[i]));
        return res * res;   
    }
}
