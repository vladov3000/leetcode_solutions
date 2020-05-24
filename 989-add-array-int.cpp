// Runtime: 52 ms, faster than 97.22% of C++ online submissions for Add to Array-Form of Integer.
// Memory Usage: 28.8 MB, less than 11.11% of C++ online submissions for Add to Array-Form of Integer.

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> result;
        
        int i = 0;
        int carry = 0;
        while (i < A.size() || K > 0) {
            int curD = K % 10 + carry;
            if (i < A.size()) curD += A[A.size() - i - 1];
            carry = curD / 10;
            curD  %= 10;
            
            result.push_back(curD);
            K /= 10;
            i++;
        }
        
        if(carry) result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};
