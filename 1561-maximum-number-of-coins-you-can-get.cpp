#include <span>

class Solution {
public:
    int maxCoins(span<int> piles) {
        sort(piles.begin(), piles.end());

        int bobs   = 0;
        int result = 0;

        for (int i = piles.size() - 2; i >= bobs; i -= 2) {
            result += piles[i];
            bobs++;
        }

        return result;
    }
};
