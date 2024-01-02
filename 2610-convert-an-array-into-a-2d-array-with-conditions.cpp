#include <span>

class Solution {
public:
    // O(n) runtime O(n) space
    vector<vector<int>> findMatrix(span<int> numbers) {
        vector<vector<int>>     result;
        unordered_map<int, int> counts;

        for (int number : numbers) {
            int row = counts[number]++;
            result.resize(max(static_cast<int>(result.size()), row + 1));
            result[row].push_back(number);
        }

        return result;
    }

    /* O(nlog(n)) runtime O(1) space
    vector<vector<int>> findMatrix(span<int> numbers) {
        sort(numbers.begin(), numbers.end());

        vector<vector<int>> result(1, vector<int>(1, numbers[0]));
        int                 streak = 1;

        for (int i = 1; i < numbers.size(); i++) {
            streak = numbers[i] == numbers[i - 1] ? streak + 1 : 1;

            if (streak > result.size())
                result.emplace_back();

            result[streak - 1].push_back(numbers[i]);
        }

        return result;
    }
    */
};
