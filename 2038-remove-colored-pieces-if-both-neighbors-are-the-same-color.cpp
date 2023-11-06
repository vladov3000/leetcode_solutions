class Solution {
public:
    bool winnerOfGame(string_view colors) {
        int triple_a = 0;
        int triple_b = 0;

        for (size_t i = 0; i < colors.size(); i++) {
            if (colors.substr(i, 3) == "AAA") {
                triple_a++;
            } else if (colors.substr(i, 3) == "BBB") {
                triple_b++;
            }
        }

        return triple_a > triple_b;
    }
};
