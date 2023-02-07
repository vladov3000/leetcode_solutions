class Solution {
public:
    bool isAlienSorted(const vector<string>& words, string_view order) {
        char letter_value[26] = {};

        for (int i = 0; i != order.size(); i++)
            letter_value[order[i] - 'a'] = 26 - i;

        for (int i = 0; i != words.size() - 1; i++) {
            string_view current = words[i];
            string_view next    = words[i + 1];

            int j;
            int min_size = min(current.size(), next.size());

            for (j = 0; j != min_size; j++) {
                char current_value = letter_value[current[j] - 'a'];
                char next_value = letter_value[next[j] - 'a'];
                if (current_value < next_value)
                    return false;
                if (current_value > next_value)
                    break;
            }

            if (j == min_size && current.size() > next.size())
                return false;
        }

        return true;
    }
};
