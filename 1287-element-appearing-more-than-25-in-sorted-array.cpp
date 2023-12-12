#include <span>

class Solution {
public:
    int findSpecialInteger(span<int> integers) {
        int count = 1;
        for (int i = 1; i < integers.size(); i++) {
            if (integers[i] == integers[i - 1]) {
                if (count >= integers.size() / 4) {
                    return integers[i];
                }
                count++;
            } else {
                count = 1;
            }
        }
        return integers.back();
    }
};
