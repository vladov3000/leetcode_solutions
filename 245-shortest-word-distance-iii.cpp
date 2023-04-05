class Solution {
public:
    int shortestWordDistance(
        const vector<string>& words, 
        string_view word1, 
        string_view word2
    ) {
        int result = INT_MAX;
        
        if (word1 == word2) {
            int start = -1;

            for (int i = 0; i < words.size(); i++) {
                if (words[i] == word1) {
                    if (start > -1) {
                        result = min(result, i - start);
                    }
                    start = i;
                }
            }

            return result;
        }

        int start[2] = { -1, -1 };

        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                if (start[1] > -1) {
                    result = min(result, i - start[1]);
                }
                start[0] = i;
            } 
            
            if (words[i] == word2) {
                if (start[0] > -1) {
                    result = min(result, i - start[0]);
                }
                start[1] = i;
            }
        }

        return result;
    }
};
