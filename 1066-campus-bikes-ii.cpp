#include <bit>
#include <span>

static int get_distance(span<int> worker, span<int> bike) {
    return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
}

class Solution {
public:
    int assignBikes(span<vector<int>> workers, span<vector<int>> bikes) {
        int      m          = bikes.size();
        int      result     = INT_MAX;
        unsigned mask_count = 1 << m;
        auto     memoized   = make_unique<int[]>(mask_count);

        for (unsigned mask = 0; mask < mask_count; mask++) {
            int worker_index = popcount(mask);
            if (worker_index >= workers.size()) {
                if (memoized[mask] > 0)
                    result = min(result, memoized[mask]);
                continue;
            }

            for (int bike_index = 0; bike_index < m; bike_index++) {
                if (mask & (1 << bike_index))
                    continue;

                int new_mask       = mask | (1 << bike_index);
                span<int> worker   = workers[worker_index];
                span<int> bike     = bikes[bike_index];
                int       distance = memoized[mask] + get_distance(worker, bike);
                if (memoized[new_mask] == 0 || distance < memoized[new_mask])
                    memoized[new_mask] = distance;
            }
        }

        return result;
    }

    /* DFS
    int assignBikes(span<vector<int>> workers, span<vector<int>> bikes) {
        vector<vector<int>> memoized(workers.size(), vector<int>(1 << bikes.size()));
        int                 taken = 0;
        return assignBikes(workers, bikes, memoized, taken, 0);
    }

    int assignBikes(
        span<vector<int>> workers, 
        span<vector<int>> bikes,
        span<vector<int>> memoized,
        int&              taken,
        int               worker_index
    ) {
        if (worker_index == workers.size())
            return 0;

        if (memoized[worker_index][taken])
            return memoized[worker_index][taken];

        int result = INT_MAX;

        for (int i = 0; i < bikes.size(); i++) {
            if (taken & (1 << i))
                continue;

            taken |= 1 << i;

            int tail = assignBikes(workers, bikes, memoized, taken, worker_index + 1);
            result   = min(result, tail + get_distance(workers[worker_index], bikes[i]));

            taken &= ~(1 << i);
        }
        
        memoized[worker_index][taken] = result;
        return result;
    }
    */
};
