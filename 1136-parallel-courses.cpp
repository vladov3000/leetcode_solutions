#include <span>

static int helper(
    span<vector<int>>   graph,
    int                 current, 
    unordered_set<int>& visited,
    span<int>           memoized
) {
    if (visited.contains(current)) {
        return INT_MAX;
    }

    if (memoized[current] != 0) {
        return memoized[current];
    }

    if (graph[current].empty()) {
        return 1;
    }
    
    visited.insert(current);

    int result = 1;
    for (int prerequisite : graph[current]) {
        int helper_result = helper(graph, prerequisite, visited, memoized);
        if (helper_result == INT_MAX) {
            return INT_MAX;
        } else {
            result = max(result, helper_result + 1);
        }
    }

    visited.erase(current);
    return result;
}

class Solution {
public:
    int minimumSemesters(int n, span<vector<int>> relations) {
        vector<vector<int>> graph(n);
        for (const auto& relation : relations) {
            graph[relation[1] - 1].push_back(relation[0] - 1);
        }

        vector<int> memoized(n);
        unordered_set<int> visited;

        int result = 0;
        for (int i = 0; i < n; i++) {
            visited.clear();
            memoized[i] = helper(graph, i, visited, memoized);
            result = max(result, memoized[i]);
        }
        return result == INT_MAX ? -1 : result;
    }
};
