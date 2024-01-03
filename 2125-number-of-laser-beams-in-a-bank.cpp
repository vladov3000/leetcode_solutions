#include <span>

class Solution {
public:
    int numberOfBeams(span<string> bank) {
        int result   = 0;
        int previous = 0;
        for (string_view row : bank) {
            int devices  = count(row.cbegin(), row.cend(), '1');
            result      += previous * devices;
            if (devices > 0) {
                previous     = devices;
            }
        }
        return result;
    }
};
