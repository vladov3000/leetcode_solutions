static int count_vowels(string_view s) {
    int result = 0;
    for (char c : s) {
        if (string_view("aeiouAEIOU").find(c) != string_view::npos) {
            result++;
        }
    }
    return result;
}

class Solution {
public:
    bool halvesAreAlike(string_view s) {
        int middle        = s.size() / 2;
        string_view front = s.substr(0, middle);
        string_view back  = s.substr(middle);
        return count_vowels(front) == count_vowels(back);
    }
};
