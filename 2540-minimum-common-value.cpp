#include <span>

class Solution {
public:
    int getCommon(span<const int> as, span<const int> bs) {
        auto a = as.begin();
        auto b = bs.begin();
        while (a != as.end() && b != bs.end()) {
            if (*a < *b) {
                a++;
            } else if (*a > *b) {
                b++;
            } else {
                return *a;
            }
        }
        return -1;
    }
};
