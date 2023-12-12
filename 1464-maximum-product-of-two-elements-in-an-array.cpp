#include <span>

class Solution {
public:
    int maxProduct(span<int> numbers) {
        int largest[2] = {};
        for (int i : numbers) {
            if (i > largest[0]) {
                largest[1] = largest[0];
                largest[0] = i;
            } else if (i > largest[1]) {
                largest[1] = i;
            }
        }
        return (largest[0] - 1) * (largest[1] - 1);
    }
};
