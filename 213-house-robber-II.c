#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MOD(x, y) (((x) + (y)) % (y))

int rob(int* nums, int nums_len) {
    if (nums_len == 1) return nums[0];
    if (nums_len == 2) return MAX(nums[0], nums[1]);
    if (nums_len == 3) return MAX(nums[0], MAX(nums[1], nums[2]));
    
    int nums_offset_0 = nums[1];
    int nums_offset_1 = MAX(nums[1], nums[2]);
    int nums_0 = nums[0];
    int nums_1 = MAX(nums[0], nums[1]);
    
    nums[1] = MAX(nums[0], nums[1]);
    
    for (int i = 2; i < nums_len - 1; i++) {
        int nums_offset_2 = MAX(nums[i + 1] + nums_offset_0, nums_offset_1);
        int nums_2 = MAX(nums[i] + nums_0, nums_1);   
        
        nums_offset_0 = nums_offset_1;
        nums_offset_1 = nums_offset_2;
        nums_0 = nums_1;
        nums_1 = nums_2;
    }
    
    return MAX(nums_1, nums_offset_1);
}
