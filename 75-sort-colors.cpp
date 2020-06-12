class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) return;
        
        int a = 0, b = nums.size() - 1;
        for (int i=0; i < b + 1; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[a]);
                a++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[b]);
                b--;
                i--;
            }
            // for (int j : nums) cout << j << ", ";
            // cout << endl;
        }
    }
};
