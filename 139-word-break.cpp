class Solution {
public:
    bool wordBreak(string_view s, const vector<string>& words) {
        vector<bool> ok(s.size() + 1);

        for (string_view word : words)
            if (s.starts_with(word))
                ok[word.size()] = true;

        for (int i = 0; i < ok.size(); i++)
            if (ok[i])
                for (string_view word : words)
                    if (s.substr(i).starts_with(word))
                        ok[i + word.size()] = true;

        return ok.back();
    }

    /* Naive O((words.size() * words[i].size()) ^ s.size()) solution
    bool wordBreak(string_view s, const vector<string>& words) {
        if (s.empty())
            return true;
        
        for (string_view word : words)
            if (s.starts_with(word))
                if (wordBreak(s.substr(word.size()), words))
                    return true;

        return false;
    }
    */
};
