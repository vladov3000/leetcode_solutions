#define MAX_SEEN_SIZE (1 << 20)

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // time complexity: O(n) where n is length of s
        // space complexity: O(1) ~2^20 bits = 2^7 bytes
        
        
        // kth bit == 1 means kth code has been seen
        auto seen = make_unique<bitset<MAX_SEEN_SIZE>>(bitset<MAX_SEEN_SIZE>{});
        unsigned int num_seen = 0;
        unsigned int prev = 0;
        
        // find first substring with length k
        for (int i = 0; i < k; i++) {
            if (i > s.length() - 1) {
                return false;
            }
            
            prev <<= 1;
            prev += s[i] - '0';
        }
        
        // find all other substrings
        // i is end of current substring
        for (int i = k; i < s.length(); i++) {
            
            // printf("%s\n", seen->to_string().substr(MAX_SEEN_SIZE - k - 5).c_str());
            
            if (!seen->test(prev)) {
                seen->set(prev, true);
                num_seen++;
            }
            
            // update prev by removing msb bit and adding lsb bit
            prev <<= 1;
            prev &= (1 << k) - 1;
            prev += s[i] - '0';
        }
        
        return (num_seen == 1 << k) || (num_seen == (1 << k) - 1 && !seen->test(prev));
    }
};
