class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.size() < s.size()) return false;
        if (s.size() == 0) return true;
        
        int a = 0;
        for (int i=0; i < t.size(); i++) {
            // cout << t[i] << " " << s[a] << endl;
            if (a > s.size() - 1) return true;
            if (t[i] == s[a]) a++;
        }
        return a == s.size();
    }
};
