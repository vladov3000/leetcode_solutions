impl Solution {
    fn helper(nums: &Vec<i32>, target: i32, mem: &mut Vec<i32>) -> i32 {
        if target < 0 {
            return 0;
        } else if mem[target as usize] > -1 {
            return mem[target as usize];
        }
            
        let mut res = 0;
        for n in nums {
            res += Solution::helper(nums, target - n, mem);
        }
        mem[target as usize] = res;
        
        res
    }
    
    pub fn combination_sum4_1(nums: Vec<i32>, target: i32) -> i32 {
        let mut mem = vec![-1; 1 + target as usize];
        mem[0] = 1;
        
        Solution::helper(&nums, target, &mut mem)
    }
    
    pub fn combination_sum4(nums: Vec<i32>, target: i32) -> i32 {
        let mut dp = Vec::with_capacity(1 + target as usize);
        dp.push(1);
        
        for i in 1..(target + 1) {
            dp.push(0);
            
            for n in &nums {
                if i - n > -1 {
                    dp[i as usize] += dp[(i - *n) as usize];
                }
            }
        }
        
        *dp.last().unwrap()
    }
}
