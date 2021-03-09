impl Solution {
    pub fn is_strobogrammatic(num: String) -> bool {
        for (i, (c1, c2)) in num.chars().zip(num.chars().rev()).enumerate() {
            if !match c1 {
                '9' => c2 == '6',
                '6' => c2 == '9',
                '1' => c2 == '1',
                '8' => c2 == '8',
                '0' => c2 == '0',
                _ => false,
            } {
                return false;
            }
        }
        
        true
    }
}
