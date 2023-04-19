class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;

        int min_size = min(word1.size(), word2.size());

        for (int i = 0; i < min_size * 2; i++)
            result.push_back(i % 2 ? word2[i / 2] : word1[i / 2]);

        for (int i = min_size; i < word1.size(); i++)
            result.push_back(word1[i]);

        for (int i = min_size; i < word2.size(); i++)
            result.push_back(word2[i]);

        return result;
    }
};
