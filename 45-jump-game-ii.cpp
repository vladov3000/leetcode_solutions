
class Solution {
public:
    int jump(vector<int>& nums) {
        int next    = 0;
        int current = 0;
        int result  = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > current) {
                current = next;
                result++;
            }
            next = max(next, i + nums[i]);
        }

        return result;
    }
};
