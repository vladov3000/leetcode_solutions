impl Solution {
    pub fn remove_palindrome_sub(s: String) -> i32 {
        if s.len() == 0 {
            return 0;
        }
        for (c1, c2) in s.chars().zip(s.chars().rev()) {
            if c1 != c2 {
                return 2;
            }
        }
        return 1;
    }
}
