class Solution {
public:
    string addBinary(string_view a, string_view b) {
        int max_size = max(a.size(), b.size());

        string result;
        result.reserve(max_size);
        int carry = 0;

        for (int i = 0; i < max_size; i++) {
            int a0 = i < a.size() ? a[a.size() - 1 - i] - '0' : 0;
            int b0 = i < b.size() ? b[b.size() - 1 - i] - '0' : 0;

            int digit = a0 + b0 + carry;
            carry = digit >> 1;
            digit = digit & 1;
            result.push_back(digit + '0');
        }

        if (carry)
            result.push_back('1');

        reverse(result.begin(), result.end());
        return result;
    }
};
