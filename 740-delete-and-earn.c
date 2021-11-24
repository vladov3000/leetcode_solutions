#define MAX(x, y) ((x) > (y) ? (x) : (y))

int deleteAndEarn(int* nums, int nums_len) {
    if (nums_len == 1) return nums[0];
    
    int freqs[10001] = { 0 };
    int max = nums[0];
    
    for (int i = 0; i < nums_len; i++) {
        freqs[nums[i]]++;
        max = MAX(max, nums[i]);
    }
    
    int dp_0 = 0;
    int dp_1 = freqs[1];
    for (int i = 2; i < max + 1; i++) {
        int dp_2 = MAX(freqs[i] * i + dp_0, dp_1);
        dp_0 = dp_1;
        dp_1 = dp_2;
    }
    
    return dp_1;
}
