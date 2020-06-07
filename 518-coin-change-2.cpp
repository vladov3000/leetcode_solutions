class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        if (coins.size() == 0) return 0;
        
        int w = coins.size();
        int h = amount + 1;
        int dp[h][w];
        
        for (int i = 0; i < w; i++) dp[0][i] = 1;
        
        for (int i = 1; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int x = (i-coins[j] >= 0) ? dp[i - coins[j]][j] : 0; 
                int y = (j >= 1) ? dp[i][j - 1] : 0;
                dp[i][j] = x + y;
            }
        }
        
        
        /* for (auto& nums : dp) {
            for (int& n : nums) printf("%10d, ", n);
            cout << endl;
        }*/
        
        return dp[h-1][w-1];
    }
};
