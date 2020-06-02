// Runtime: 8 ms, faster than 98.23% of C++ online submissions for Move Zeroes.
// Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Move Zeroes.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int a = 0; // non zero num
        int b = 0; // zero
        while (a < nums.size()) {
            if (nums[a] != 0) swap(nums[a], nums[b++]);
            a++;
        }
    }
};
