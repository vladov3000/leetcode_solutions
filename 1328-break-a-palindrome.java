class Solution {
    public String breakPalindrome(String palindrome) {
        if (palindrome.length() == 1) {
            return "";
        }
        
        StringBuilder res = new StringBuilder();
        boolean found = false;
            
        for (int i = 0; i < palindrome.length(); i++) {
            char c = palindrome.charAt(i);
            
            if (c != 'a' && !found && i < palindrome.length() / 2) {
                found = true;
                res.append('a');
            } else {
                res.append(c);
            }
        }
        
        if (!found) {
            res.deleteCharAt(res.length() - 1);
            res.append('b');
        }
        
        return res.toString();
    }
}
