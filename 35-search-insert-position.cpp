class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int middle = (start + end) / 2;

            if (nums[middle] < target)
                start = middle + 1;
            else if (nums[middle] > target)
                end = middle - 1;
            else
                return middle;
        }

        return nums[start] < target ? start + 1 : start;
    }
};
