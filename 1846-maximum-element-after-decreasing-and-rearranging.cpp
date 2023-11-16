#include <span>

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(span<int> array) {
        sort(array.begin(), array.end());

        array[0] = 1;

        for (int i = 1; i < array.size(); i++) {
            if (array[i] - array[i - 1] > 1) {
                array[i] = array[i - 1] + 1;
            }
        }

        return array.back();
    }
};
