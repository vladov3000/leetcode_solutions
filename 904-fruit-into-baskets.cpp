static int sum_counts(const unordered_map<int, int>& counts) {
    int result = 0;
    for (const auto& entry : counts)
        result += entry.second;
    return result;
}

class Solution {
public:
    int totalFruit(const vector<int>& fruits) {
        unordered_map<int, int> counts;
        int result = 0;
        int start = 0;

        for (int i = 0; i < fruits.size(); i++) {
            counts[fruits[i]]++;
            
            while (counts.size() > 2)
                if (!--counts[fruits[start++]])
                 counts.erase(fruits[start - 1]);

            result = max(result, sum_counts(counts));
        }

        return result;
    }
};
