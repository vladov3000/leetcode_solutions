int max(int a, int b) {
    return a > b ? a : b;
}

int longestSubarray(int* nums, int size){
    int  previous = 0;
    int  current  = 0;
    int  result   = 0;
    bool all_ones = true;

    for (int i = 0; i < size; i++) {
        if (nums[i] == 0) {
            result   = max(result, current + previous);
            previous = current;
            current  = 0;
            all_ones = false;
        } else {
            current++;
        }
    }

    if (all_ones)
        return size - 1;
    else
        return max(result, current + previous);
}
