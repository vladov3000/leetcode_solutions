impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        
        let mut res = String::new();
        let mut num = num;
        
        while num > 0 {
            let (numeral, delta) = match num {
                num if num >= 1000 => ("M", 1000),
                num if num >= 900 => ("CM", 900),
                num if num >= 500 => ("D", 500),
                num if num >= 400 => ("CD", 400),
                num if num >= 100 => ("C", 100),
                num if num >= 90 => ("XC", 90),
                num if num >= 50 => ("L", 50),
                num if num >= 40 => ("XL", 40),
                num if num >= 10 => ("X", 10),
                num if num >= 9 => ("IX", 9),
                num if num >= 5 => ("V", 5),
                num if num >= 4 => ("IV", 4),
                num if num >= 3 => ("III", 3),
                num if num >= 2 => ("II", 2),
                num if num >= 1 => ("I", 1),
                _ => panic!(),
            };
        
            res.push_str(numeral);
            num -= delta;
        }
        
        res
    }
}
