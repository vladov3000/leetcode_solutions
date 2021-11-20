#define MAX(x, y) ((x) > (y) ? (x) : (y))

int rob(int* nums, int nums_len) {
    if (nums_len == 1) return nums[0];
    nums[1] = MAX(nums[0], nums[1]);
    if (nums_len == 2) return nums[1];
    
    for (int i = 2; i < nums_len; i++) {
        nums[i] = MAX(nums[i] + nums[i - 2], nums[i - 1]);
    }
    
    return nums[nums_len - 1];
}
