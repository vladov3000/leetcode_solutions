// Runtime: 8 ms, faster than 71.55% of C++ online submissions for Fizz Buzz.
// Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Fizz Buzz.

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> out;
        
        for (int i = 1; i < n + 1; i++) {
            string s;
            if (i > 2 && i % 3 == 0) s += "Fizz";
            if (i > 4 && i % 5 == 0) s += "Buzz";
            if (s.size() == 0) s += to_string(i);
            out.push_back(s);
        }
        
        return out;
    }
};
