// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Happy Number.

class Solution {
public:
    bool isHappy(int n) {
        if (n < 1) return false;
        
        set <int, greater <int>> seen;
        
        while (n != 1) {
            if (seen.find(n) != seen.end()) return false;
            seen.insert(n);
            int sqSum = 0;
            while (n > 0) {
                sqSum += pow(n % 10, 2);
                n /= 10;
            }
            n = sqSum;
            cout << n << endl;
        }
        return true;
    }
};
