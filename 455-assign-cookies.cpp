#include <span>

class Solution {
public:
    int findContentChildren(span<int> appetites, span<int> sizes) {
        sort(appetites.begin(), appetites.end(), greater {});
        sort(sizes.begin(), sizes.end(), greater {});

        int  result   = 0;
        auto size     = sizes.begin();
        auto appetite = appetites.begin();
        while (size != sizes.end() && appetite != appetites.end()) {
            if (*size >= *appetite) {
                result++;
                size++;
            }
            appetite++;
        }
        return result;
    }
};
