#include <span>

class Solution {
public:
    int maxProfit(span<int> prices) {
        int result  = 0;
        int minimum = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            result  = max(result, prices[i] - minimum);
            minimum = min(minimum, prices[i]);
        }
        return result;
    }
};
