impl Solution {
    fn wiggle_max_length_helper(nums: &Vec<i32>, up: bool) -> i32 {
        // up represents whether the first difference 
        // in the wiggle should be greater than or less than 0
        
        // iterator over pairs of adjacent elements
        let n_iter = nums.iter().zip(nums.iter().skip(1));
        
        // the accumulated value will contain the length
        // of the wiggle sequence up to index i in a tuple and 
        // whether the next difference must be greater or less than 0
        n_iter.fold((1, up), |(len, up), (n1, n2)| {
            if up ^ (n1 > n2) && n1 != n2 {
                (len + 1, !up)
            } else {
                // ignore elements that would make
                // our wiggle sequence invalid
                (len, up)
            }
        }).0
    }
    
    pub fn wiggle_max_length(nums: Vec<i32>) -> i32 {
        
        // we partition the problem into two cases:
        // when the first pair of elements in the wiggle sequence has a 
        // positive (resp. negative) difference
        let res_up = Solution::wiggle_max_length_helper(&nums, true);
        let res_down = Solution::wiggle_max_length_helper(&nums, false);
        
        res_up.max(res_down)
    }
}
