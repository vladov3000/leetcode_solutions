/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int nums_len, int* res_len) {
    
    int* res = calloc(sizeof(int), nums_len);
    *res_len = 0;
    
    for (int i = 0; i < nums_len; i++) res[nums[i] - 1] = true;
    for (int i = 0; i < nums_len; i++) {
        if (!res[i]) {
            res[*res_len] = i + 1;
            (*res_len)++;
        }
    }
    
    return res;
}
