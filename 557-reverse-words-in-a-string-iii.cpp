class Solution {
public:
    string reverseWords(string s) {
        auto word = s.begin();

        while (true) {
            auto next_space = find(word, s.end(), ' ');

            reverse(word, next_space);

            if (next_space == s.end()) {
                break;
            }

            word = ++next_space;
        }

        return s;
    }

    /*
    string reverseWords(string_view s) {
        string result;

        while (true) {
            size_t next_space = s.find(' ');
            string_view word  = s.substr(0, next_space);

            result.append(word.crbegin(), word.crend());
            if (next_space == string_view::npos) {
                break;
            }

            result.push_back(' ');
            s = s.substr(next_space + 1);
        }

        return result;
    }
    */
};
