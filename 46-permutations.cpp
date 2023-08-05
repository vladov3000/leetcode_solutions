void helper(
    int                  index,
    vector<int>&         permutation,
    const vector<int>&   numbers,
    vector<vector<int>>& result
) {
    if (index == numbers.size()) {
        result.emplace_back(permutation);
        return;
    }

    for (int i = 0; i < permutation.size(); i++) {
        if (permutation[i] == INT_MAX) {
            permutation[i] = numbers[index];
            helper(index + 1, permutation, numbers, result);
            permutation[i] = INT_MAX;
        }
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& numbers) {
        vector<int>         permutation(numbers.size(), INT_MAX);
        vector<vector<int>> result;
        helper(0, permutation, numbers, result);
        return result;
    }
};
