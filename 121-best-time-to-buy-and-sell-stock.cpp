class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int running_min = prices[0];
        int result = 0;

        for (int i = 1; i < prices.size(); i++) {
            running_min = min(running_min, prices[i]);
            result = max(result, prices[i] - running_min);
        }

        return result;
    }
};
