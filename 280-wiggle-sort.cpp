class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool up = true;

        for (int i = 1; i < nums.size(); i++) {
            if (up == nums[i - 1] > nums[i])
                swap(nums[i - 1], nums[i]);
                
            up = !up;
        }
    }

    void wiggleSortSlow(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater());

        for (int i = 1; i < nums.size(); i += 2)
            swap(nums[i], nums[i - 1]);
    }
};
