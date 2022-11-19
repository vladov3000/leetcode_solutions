class Solution {
public:
    int shortestWay(string_view source, string_view target) {
        for (char c : target)
            if (source.find(c) == source.npos)
                return -1;

        string_view subsequence = source;
        int result = 0;

        while (!target.empty()) {
            if (subsequence[0] == target[0])
                target.remove_prefix(1);

            subsequence.remove_prefix(1);
            if (subsequence.empty())
                subsequence = source, result++;
        }

        if (subsequence.size() < source.size())
            result++;

        return result;
    }
};
