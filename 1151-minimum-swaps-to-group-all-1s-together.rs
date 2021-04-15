impl Solution {
    pub fn min_swaps1(data: Vec<i32>) -> i32 {
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
    
    pub fn min_swaps(data: Vec<i32>) -> i32 {
        let total: i32 = data.iter().sum();
        let init = total - data.iter().take(total as usize).sum::<i32>();
        
        data.iter().zip(data.iter().skip(total as usize)).fold((init, init), 
            |(acc, prev), (start, new)| {
                let cur = prev - (*start == 0) as i32 + (*new == 0) as i32;
                (acc.min(cur), cur) 
            }
        ).0
    }
}
