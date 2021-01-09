class Solution {
public:
    bool canPermutePalindrome(string s) {
        int freqs[256];
        for (int i = 0; i < 256; i++) {
            freqs[i] = 0;
        }
        
        for (char c : s) {
            freqs[c]++;
        }
        
        bool middleUsed = s.length() % 2 == 0;
        for (int i : freqs) {
            if (i % 2) {
                if (!middleUsed) {
                    middleUsed = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
