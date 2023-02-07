class Solution {
public:
    bool checkInclusion(string_view s1, string_view s2) {
        if (s1.size() > s2.size())
            return false;

        array<int, 26> target = {};
        for (char c : s1)
            target[c - 'a']++;

        array<int, 26> current = {};
        for (int i = 0; i < s1.size(); i++)
            current[s2[i] - 'a']++;

        if (current == target)
            return true;

        for (int i = s1.size(); i < s2.size(); i++) {
            current[s2[i - s1.size()] - 'a']--;
            current[s2[i] - 'a']++;

            if (current == target)
                return true;
        }

        return false;
    }
};
