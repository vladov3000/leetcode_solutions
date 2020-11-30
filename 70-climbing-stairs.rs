impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if (n == 0) { return 0; }
        
        let mut res = (0, 1);
        for _ in 1..(n+1) {
            res = (res.1, res.0 + res.1);
            // print!("{:?}\n", res);
        }
        res.1
    }
    
    pub fn climb_stairs1(n: i32) -> i32 {
        let mut dp = vec![0, 1, 2];
        for i in 3..(n+1) {
            dp.push(dp[(i-1) as usize] + dp[(i-2) as usize]);
        }
        // print!("{:?}", dp);
        dp[n as usize]
    }
}
