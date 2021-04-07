impl Solution {
    
    // returns 1 if vowel else 0
    fn is_vowel(c: char) -> u32 {
        match c {
            'a' | 'e' | 'i' |'o' | 'u' |
            'A' | 'E' | 'I' | 'O' | 'U' => 1,
            _ => 0,
        }
    }
    
    pub fn halves_are_alike(s: String) -> bool {
        let vowel_counts = s.chars()
            .zip(s.chars().skip(s.len() / 2))
            .fold((0, 0), |acc, (c1, c2)| {
                  (acc.0 + Solution::is_vowel(c1), acc.1 + Solution::is_vowel(c2))
            });
        
        vowel_counts.0 == vowel_counts.1
    }
}
