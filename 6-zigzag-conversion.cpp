class Solution {
public:
    string convert(string_view s, int numRows) {
        if (numRows == 1)
            return string(s);

        string result;
        result.reserve(s.size());

        int delta = 2 * numRows - 2;

        // Top row.
        for (int i = 0; i < s.size(); i += delta)
            result.push_back(s[i]);

        // Middle rows
        for (int i = 1; i < numRows - 1; i++)
            for (int j = i; j < s.size(); j += delta) {
                result.push_back(s[j]);
                
                int other = j + delta - 2 * i;
                if (other < s.size())
                    result.push_back(s[other]);
            }

        // Bottom row.
        for (int i = numRows - 1; i < s.size(); i += delta)
            result.push_back(s[i]);

        return result;
    }
};
