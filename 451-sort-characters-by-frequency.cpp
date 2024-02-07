class Solution {
public:
    string frequencySort(string& s) {
        unordered_map<char, int> frequencies;
        for (char c : s) {
            frequencies[c]++;
        }

        sort(s.begin(), s.end());

        stable_sort(s.begin(), s.end(), [&](char a, char b) { 
            return frequencies[a] > frequencies[b]; 
        });
        return s;
    }
};
