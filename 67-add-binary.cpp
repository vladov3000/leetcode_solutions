// Runtime: 4 ms, faster than 83.69% of C++ online submissions for Add Binary.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Add Binary.


class Solution {
public:
    string addBinary(string a, string b) {
        string out;
        
        int carry = 0;
        int idx = 0;
        while (idx < a.size() || idx < b.size()) {
            int digit = 0;
            if (idx < a.size()) digit += (int) a[a.size() - idx - 1] - (int) '0';
            if (idx < b.size()) digit += (int) b[b.size() - idx - 1] - (int) '0';
            digit += carry;
            carry = digit / 2;
            digit = digit % 2;
            out += (char) (digit + (int) '0');
            idx++;
        }
        if (carry) out += "1";
        reverse(out.begin(), out.end());
        
        return out;
    }
};
