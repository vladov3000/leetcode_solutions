/*
char* longestPalindrome(char* s) {
    int len   = strlen(s);
    int start = 0;
    int end   = 0;
    
    for (int i = 0; i < len; i++) {
        for (int j = -1; j != 1; j++) {
            int left   = i + j;
            int right  = i + 1;

            while (left != -1 && right != len && s[left] == s[right]) {
                left--;
                right++;
            }
            
            left++;
            right--;

            if (right - left > end - start) {
                start = left;
                end   = right;
            }
        }
    }
    
    s[end + 1] = '\0';
    return s + start;
}
*/

int min(int x, int y) {
    return x < y ? x : y;
}

bool even(int n) {
    return n & 1;
}

// `get` surrounds each character in a string with pipes,
// including the start and end. e.g. "cbbd" => "|c|b|b|d|".
// This is used to make every substring palindrome have an odd length,
// such that we can represent a palindrome with the index of its center
// and its radius.
//
// The new string's length is 2 * strlen(s) + 1 and you can map indexes
// back to s by dividing them by 2.
// 
char get(char* s, int idx) {
    return even(idx) ? s[idx / 2] : '|';
}

char* longestPalindrome(char* s) {
    int len = strlen(s) * 2 + 1;
    
    int* radii = malloc(sizeof(int) * len);
    memset(radii, 0, sizeof(int) * len);
    
    int center = 0;
    int radius = 0;
    
    int result_center = 0;
    
    while (center < len) {
        while (center - radius - 1 >= 0 &&
              center + radius + 1 < len &&
              get(s, center - radius - 1) == get(s, center + radius + 1))
            radius++;
        
        radii[center] = radius;
        if (radii[center] > radii[result_center])
            result_center = center;
        
        int old_center = center;
        int old_radius = radius;
        
        center++;
        radius = 0;
        
        while (center <= old_center + old_radius) {
            int mirrored_center = old_center - (center - old_center);
            int max_mirrored_radius = old_radius - (center - old_center);
            int mirrored_radius = radii[mirrored_center];
            
            if (mirrored_radius == max_mirrored_radius) {
                radius = max_mirrored_radius;
                break;
            }
            
            radii[center] = min(max_mirrored_radius, mirrored_radius);
            if (radii[center] > radii[result_center])
                result_center = center;
            center++;
        }
    }
    
    
    int result_radius = radii[result_center] - 1;
    int start = (result_center - result_radius) / 2;
    int end = (result_center + result_radius) / 2;
    s[end + 1] = '\0';
    return s + start;
}
