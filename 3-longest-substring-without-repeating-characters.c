#define MAX(x, y) ((x) > (y) ? (x) : (y))

int lengthOfLongestSubstring(char* s) {
    // last_offset[c] = 0 => character c has not been recorded yet
    // last_offset[c] = x => s[x - 1] = c
    int last_offsets[CHAR_MAX] = {};
    
    // We consider the substrings s[start..i] (inclusive) 
    // and s[i..j] where s[i] != s[k] for i < k <= j and 0 <= i, j < length of s
    int start = 0;

    int result = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        int last_offset = last_offsets[c];
        
        if (last_offset != 0)
            start = MAX(start, last_offset);
            
        result = MAX(result, i - start + 1);
        last_offsets[c] = i + 1;
    }

    return result;
}
