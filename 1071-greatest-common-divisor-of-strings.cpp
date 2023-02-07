class Solution {
public:
    string gcdOfStrings(string_view x, string_view y) {
        if (x.size() > y.size())
            return gcdOfStrings(y, x);

        if (y.substr(0, x.size()) != x)
            return "";

        if (x.empty())
            return string(y);

        return gcdOfStrings(x, y.substr(x.size()));
    }
};
