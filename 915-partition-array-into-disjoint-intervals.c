#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int partitionDisjoint(int* nums, int nums_size){
    if (nums_size == 2) {
        return 1;
    }
    
    int* rolling_min = malloc(sizeof(int) * nums_size);
    rolling_min[nums_size - 1] = nums[nums_size - 1];
    for (int i = 1; i < nums_size; i++) {
        int j = nums_size - 1 - i;
        rolling_min[j] = MIN(rolling_min[j + 1], nums[j]);
    }
    
    int res = -1;
    int max = nums[0];
    for (int i = 0; i < nums_size - 1; i++) {
        max = MAX(max, nums[i]);
        if (max <= rolling_min[i + 1]) {
            res = i + 1;
            break;
        }
    }
        
    free(rolling_min);
    return res;
}
