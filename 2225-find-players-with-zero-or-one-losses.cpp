#include <span>

class Solution {
public:
    vector<vector<int>> findWinners(span<vector<int>> matches) {
        set<int>                players;
        unordered_map<int, int> losses;

        for (const vector<int>& match : matches) {
            players.insert(match[0]);
            players.insert(match[1]);
            losses[match[1]]++;
        }

        vector<vector<int>> result(2);
        for (int player : players) {
            const auto entry = losses.find(player);
            if (entry == losses.cend()) {
                result[0].push_back(player);
            } else if (entry->second == 1) {
                result[1].push_back(player);
            }
        }
        return result;
    }
};
