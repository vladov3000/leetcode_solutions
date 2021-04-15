impl Solution {
    pub fn min_swaps(data: Vec<i32>) -> i32 {
        let total: i32 = data.iter().sum();
        let mut prev = total - data.iter().take(total as usize).sum::<i32>();
        let mut res = prev;
        
        for (start, new) in data.iter().zip(data.iter().skip(total as usize)) {
            let cur = prev - (*start == 0) as i32 + (*new == 0) as i32;
            
            res = res.min(cur);
            prev = cur;
        }
        
        res
    }
}
