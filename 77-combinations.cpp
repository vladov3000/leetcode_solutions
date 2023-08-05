void helper(
    int                  low,
    int                  n, 
    int                  k,
    vector<int>&         current,
    vector<vector<int>>& result
) {
    if (current.size() == k) {
        result.emplace_back(current);
        return;
    }

    int needed    = k - current.size();
    int remaining = n - low + 1;
    int available = remaining - needed;

    for (int i = low; i <= low + available; i++) {
        current.push_back(i);
        helper(i + 1, n, k, current, result);
        current.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>         current;
        vector<vector<int>> result;
        helper(1, n, k, current, result);
        return result;
    }
};
