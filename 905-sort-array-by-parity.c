static inline void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int nums_len, int* res_len) {
    int even_start = -1; // exclusive
    
    for (int i = 0; i < nums_len; i++) {
        if (nums[i] % 2 == 0) {
            even_start++;
            swap(nums + i, nums + even_start);
        }
    }
    
    *res_len = nums_len;
    return nums;
}

// In haskell, this is just
// sortArrayByParity arr = (filter even arr) ++ (filter odd arr)
