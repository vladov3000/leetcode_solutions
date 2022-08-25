class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string_view prefix = strs[0];
        
        for (auto i = 1; i < strs.size(); i++) {
            auto new_size = 0;
            while (new_size < strs[i].size() && 
                   prefix[new_size] == strs[i][new_size])
                new_size++;
            prefix = prefix.substr(0, new_size);
        }
        
        return move(string(prefix));
    }
};
