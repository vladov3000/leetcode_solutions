// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;


impl Solution {
    pub fn lowest_common_ancestor(root: Option<Rc<RefCell<TreeNode>>>, p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        
        let p = p.unwrap().borrow().val;
        let q = q.unwrap().borrow().val;
        
        // DFS
        let mut stack = VecDeque::new();
        stack.push_back(root.clone());
        let mut res = root.clone();
        
        while !stack.is_empty() {
            let cur = stack.pop_front().unwrap();
            if cur.is_none() {
                return res;
            }
            let cur = cur.clone().unwrap();
            let cur_val = cur.borrow().val;
            
            if cur_val > p && cur_val > q {
                stack.push_back(cur.borrow().left.clone());
            } else if cur_val < p && cur_val < q {
                stack.push_back(cur.borrow().right.clone());
            } else {
                return Some(cur);
            }
        }
        
        res
    }
}
