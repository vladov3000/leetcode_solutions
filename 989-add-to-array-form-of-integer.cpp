class Solution {
public:
    vector<int> addToArrayForm(const vector<int>& num, int k) {
        vector<int> result;
        result.reserve(num.size());

        int carry = 0;
        int idx = num.size() - 1;

        while (k > 0 || idx > -1) {
            int sum = (idx > -1 ? num[idx] : 0) + k % 10 + carry;
            carry = sum / 10;
            sum = sum % 10;
            result.push_back(sum);

            if (idx > -1)
                idx--;
            k /= 10;
        }

        if (carry)
            result.push_back(carry);

        reverse(result.begin(), result.end());
        return result;
    }
};
