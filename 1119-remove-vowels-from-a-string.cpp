static const unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };

class Solution {
public:
    string removeVowels(string_view input) {
        string output;
    
        for (char c : input) {
            if (!vowels.contains(c)) {
                output.push_back(c);
            }
        }

        return output;
    }
};
