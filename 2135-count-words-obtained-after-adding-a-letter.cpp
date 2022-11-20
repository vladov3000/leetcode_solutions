static unsigned long letters_used(const string& s) {
    unsigned long result = 0;
    for(char c : s)
        result |= 1 << (c - 'a');
    return result;
}

class Solution {
public:
    int wordCount(const vector<string>& startWords, 
                  const vector<string>& targetWords) {
        unordered_set<unsigned long> starts;
        for (const auto& start : startWords)
            starts.insert(letters_used(start));

        int result = 0;
        for (const auto& target : targetWords) {
            auto target_letters = letters_used(target);
            for (int i = 0; i < 26; i++) {
                if (!((target_letters >> i) & 1))
                    continue;
                if (starts.find(target_letters & ~(1 << i)) != starts.cend()) {
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};
