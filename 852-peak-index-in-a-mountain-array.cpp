int helper(const vector<int>& array, int start, int end) {
    int middle = (end + start) / 2;
    if (start >= end)
        return middle;
    else if (array[middle] > array[middle + 1])
        return helper(array, start, middle);
    else
        return helper(array, middle + 1, end);
}

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& array) {
        return helper(array, 0, array.size() - 1);
    }
};
