class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result = { nums.front() };
        for (auto it = nums.cbegin() + 1; it != nums.cend(); it++)
            result.push_back(*it + result.back());
        return result;
    }
};
