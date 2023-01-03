class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int result = 0;
        auto size = strs[0].size();

        for (decltype(size) i = 0; i < size; i++) {
            auto compare = [i](const string& x, const string& y) -> bool {
                return x[i] < y[i];
            };
            if (!std::is_sorted(strs.cbegin(), strs.cend(), compare))
                result++;
        }
        return result;
    }
};
