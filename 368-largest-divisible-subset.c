void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// partitions with the last element of nums as the pivot
int partition(int* nums, int nums_len) {
    int partition_idx = nums_len - 1;
    int idx = 0;
    for (int i = 0; i < nums_len - 1; i++) {
        if (nums[i] < nums[partition_idx]) {
            swap(&nums[i], &nums[idx]);
            idx++;
        }
    }
    swap(&nums[idx], &nums[partition_idx]);
    return idx;
}

void quick_sort(int* nums, int nums_len) {
    if (nums_len < 2) return;
    
    int partition_idx = partition(nums, nums_len);
    quick_sort(nums, partition_idx);
    quick_sort(nums + partition_idx + 1, nums_len - partition_idx - 1);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestDivisibleSubset(int* nums, int nums_len, int* res_len) {
    quick_sort(nums, nums_len);
    
    // res_lens[2 * i] is the length of the result of largestDivisibleSubset(nums, i, ...)
    // res_lens[2 * i + 1] is last diviser in that result
    int res_lens[2000];
    int max_res_len_idx = 0;
    
    // compute res_lens
    for (int i = 0; i < nums_len; i++) {
        res_lens[2 * i] = 1;
        res_lens[2 * i + 1] = -1;
        
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0) {
                if (res_lens[2 * i] < res_lens[2 * j] + 1) {
                    res_lens[2 * i] = res_lens[2 * j] + 1;
                    res_lens[2 * i + 1] = j;
                }
            }
        }
        
        if (res_lens[2 * i] > res_lens[2 * max_res_len_idx]) {
            max_res_len_idx = i;
        }
    }
    
    // copy out max_res_len and all its divisors to res
    *res_len = res_lens[2 * max_res_len_idx];
    int* res = (int*) malloc(sizeof(int) * *res_len);
    
    int idx = 0;
    for (int i = max_res_len_idx; 
         i != -1; 
         i = res_lens[2 * i + 1]) {
        
        res[idx] = nums[i];
        idx++;
    }
    
    return res;
}
