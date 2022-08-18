
int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

/*
int maxArea(int* heights, int size) {
    int result = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result = max(result, min(heights[i], heights[j]) * (j - i));
    return result;
}
*/

int maxArea(int* heights, int size) {
    int start    = 0;
    int end      = size - 1;
    int max_area = -1;
    
    while (start <= end) {
        int area = min(heights[start], heights[end]) * (end - start);
        if (area > max_area)
            max_area = area;
        
        if (heights[start] < heights[end])
            start++;
        else
            end--;
    }
    
    return max_area;
}
