class Solution {
public:
    int numIdenticalPairs(const vector<int>& numbers) {
        int                     result = 0;
        unordered_map<int, int> seen;

        for (int number : numbers) {
            if (seen[number]) {
                result += seen[number];
            }
            seen[number]++;
        }

        return result;
    }
};
