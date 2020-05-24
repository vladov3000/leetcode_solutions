// Runtime: 12 ms, faster than 48.30% of C++ online submissions for Add Strings
// Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Add Strings.

class Solution {
public:
    string addStrings(string num1, string num2) {
        
        while (num1.length() < num2.length()) num1.insert(0, 1, '0');
        while (num2.length() < num1.length()) num2.insert(0, 1, '0');
        
        vector<char> v;
        int carry = 0;
        for (int i = num1.length()-1; i >= 0; i --) {
            int cSum = num1[i] + num2[i] - 2 * '0' + carry;
            carry = cSum / 10;
            cSum %= 10;
            
            // cout << cSum << ' ' << carry << endl;
            // cout << std::string(v.begin(), v.end()) << endl;
            v.push_back((char) (cSum + '0'));
        }
        
        if (carry) v.push_back((char) (carry + '0'));
        reverse(v.begin(), v.end());
        return std::string(v.begin(), v.end());
    }
};
