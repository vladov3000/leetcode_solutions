int singleNumber(int* nums, int size) {
    int sum   = 0;
    int zeros = 0;
    
    for (int i = 0; i < size; i++)
        if (nums[i] == 0)
            zeros++;
        else
            sum ^= nums[i];

    return zeros == 1 ? 0 : sum;
}
