#include <span>

class Solution {
public:
    int maxDistance(span<vector<int>> arrays) {
        int result  = 0;
        int minimum = arrays[0].front();
        int maximum = arrays[0].back();

        for (int i = 1; i < arrays.size(); i++) {
            result  = max(result, abs(arrays[i].back() - minimum));
            result  = max(result, abs(arrays[i].front() - maximum));
            minimum = min(minimum, arrays[i].front());
            maximum = max(maximum, arrays[i].back());
        }

        return result;
    }
};
