#include <span>

long square(long x) {
    return x * x;
}

long square_distance(span<int> a, span<int> b) {
    return square(a[0] - b[0]) + square(a[1] - b[1]);
}

void helper(span<vector<int>> bombs, unordered_set<int>& visited, int index) {
    if (visited.contains(index)) {
        return;
    }

    visited.insert(index);

    for (int i = 0; i < bombs.size(); i++) {
        long distance2 = square_distance(bombs[index], bombs[i]);
        long radius2   = square(bombs[index][2]);

        if (i != index && distance2 <= radius2) {
            helper(bombs, visited, i);
        }
    }
}

class Solution {
public:
    int maximumDetonation(span<vector<int>> bombs) {
        int result = 1;

        for (int i = 0; i < bombs.size(); i++) {
            unordered_set<int> visited;
            helper(bombs, visited, i);
            result = max(result, static_cast<int>(visited.size()));
        }

        return result;
    }
};
