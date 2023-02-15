class Solution {
public:
    int countOdds(int low, int high) {
        int result = 0;

        if (low == high)
            return low & 1;

        if (low & 1)
            result++, low++;

        if (high & 1)
            result++, high--;

        result += (high - low) / 2;
        return result;
    }
};
