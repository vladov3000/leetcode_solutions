impl Solution {
    pub fn count_binary_substrings(s: String) -> i32 {
        let mut cur = s.chars().next().unwrap();
        let mut prev_count = 0;
        let mut count = 0;
        let mut res = 0;
        
        for c in s.chars() {
            if c == cur {
                count += 1;
            } else if c != cur {
                res += count.min(prev_count);
                prev_count = count;
                count = 1;
                cur = c;
            }
        }
        res += count.min(prev_count);
        
        res
    }
}
