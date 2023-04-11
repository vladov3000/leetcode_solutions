class Solution {
public:
    string removeStars(string s) {
        string result;

        int stars = 0;

        for (int i = s.size() - 1; i >= 0; i--)
            if (s[i] == '*')
                stars++;
            else if (stars > 0)
                stars--;
            else
                result.push_back(s[i]);
        
        for (int i = 0; i < result.size() / 2; i++)
            swap(result[i], result[result.size() - 1 - i]);

        return result;
    }
};
