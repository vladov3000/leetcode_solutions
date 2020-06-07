class Solution {
public:
    bool isValid(string s) {
        stack <int> stac;
        unordered_map <char, char> m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';
        
        for (char &c : s) {
            if (m.find(c) != m.end()) {
                stac.push(m[c]);
            } else {
                if (stac.size() == 0) return false;
                if (stac.top() != c) return false;
                stac.pop();
            }
        }
        if (stac.size() > 0) return false;
        
        return true;
    }
};
