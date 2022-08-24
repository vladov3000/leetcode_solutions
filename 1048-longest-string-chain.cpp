class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& x, const string& y) {
            return x.size() < y.size();
        });
        
        unordered_map<string_view, int> dp;
        
        auto it = words.begin();
        while (it != words.cend() && it->size() == 1) {
            dp[*it] = 1;
            it++;
        }
        
        int result = 1;
        
        while (it != words.cend()) {
            int chain_length = 1;
            
            for (auto i = 0; i < it->size(); i++) {
                string prev_word(*it);
                prev_word.erase(i, 1);
                
                if (dp.find(prev_word) == dp.end())
                    continue;
                
                chain_length = max(chain_length, dp.at(prev_word) + 1);
            }
            
            result = max(result, chain_length);
            dp[*it] = chain_length;
            it++;
        }

        return result;
    }
};
