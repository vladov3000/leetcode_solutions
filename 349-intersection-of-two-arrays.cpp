#include <span>

class Solution {
public:
    vector<int> intersection(span<int> a, span<int> b) {
        unordered_set<int> a_set(a.begin(), a.end());
        unordered_set<int> intersection;
        for (int n : b) {
            if (a_set.contains(n)) {
                intersection.insert(n);
            }
        }

        vector<int> result(intersection.cbegin(), intersection.cend());
        return result;
    }
};
