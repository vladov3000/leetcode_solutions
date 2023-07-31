int min(int a, int b) {
    return a < b ? a : b;
}

int minSubArrayLen(int target, int* numbers, int size) {
    int start  = 0;
    int end    = 0;
    int sum    = 0;
    int length = INT_MAX;

    while (start < size) {
        if (sum >= target) {
            length  = min(length, end - start);
            sum    -= numbers[start++];
        } else if (end == size) {
            break;
        } else {
            sum += numbers[end++];
        }
    }

    return length == INT_MAX ? 0 : length;
}
