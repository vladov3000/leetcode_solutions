class Solution {
public:
    int calculateTime(string_view keyboard, string_view word) {
        int key_to_position[26] = {};
        for (int i = 0; i < keyboard.size(); i++)
            key_to_position[keyboard[i] - 'a'] = i;

        int position = 0;
        int result   = 0;
        for (char c : word) {
            int new_position  = key_to_position[c - 'a'];
            result           += abs(new_position - position);
            position          = new_position;
        }
        return result;
    }
};
