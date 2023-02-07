class Solution {
public:
    vector<int> findAnagrams(string_view s, string_view p) {
        if (p.size() > s.size())
            return vector<int>();

        array<int, 26> target = {};
        for (char c : p)
            target[c - 'a']++;

        array<int, 26> current = {};
        for (int i = 0; i < p.size(); i++)
            current[s[i] - 'a']++;

        vector<int> result;

        if (current == target)
            result.push_back(0);

        for (int i = p.size(); i < s.size(); i++) {
            current[s[i - p.size()] - 'a']--;
            current[s[i] - 'a']++;

            if (current == target)
                result.push_back(i - p.size() + 1);
        }

        return move(result);
    }
};
