class Solution {
public:
    vector<string> generatePossibleNextMoves(string_view current) {
        vector<string> result;
        for (int i = 1; i < current.size(); i++) {
            if (current[i - 1] == '+' && current[i] == '+') {
                string next;
                next.append(current.substr(0, i - 1));
                next.append("--");
                next.append(current.substr(i + 1));
                result.emplace_back(move(next));
            }
        }
        return result;
    }
};
