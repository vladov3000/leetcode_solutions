class Solution {
public:
    int countPalindromicSubsequence(string_view s) {
      int result = 0;

      for (char c = 'a'; c <= 'z'; c++) {
        size_t left  = s.find(c);
        if (left == s.npos)
          continue;

        size_t right = s.rfind(c);
        if (right == left)
          continue;

        bitset<26> seen;
        for (size_t i = left + 1; i < right; i++) {
          seen.set(s[i] - 'a');
        }
        result += seen.count();
      }

      return result;
    }
};
