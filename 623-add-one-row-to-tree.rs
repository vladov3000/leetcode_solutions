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

struct State {
    d: i32,
    node: Rc<RefCell<TreeNode>>,
}

impl Solution {
    pub fn add_one_row(root: Option<Rc<RefCell<TreeNode>>>, v: i32, d: i32) -> Option<Rc<RefCell<TreeNode>>> {
        
        // check root is not None
        if root.is_none() {
            return None;
        }
        let root = root.unwrap();
        
        // check d = 1 case
        if d == 1 {
            let mut res = TreeNode::new(v);
            res.left = Some(root);
            
            return Some(Rc::new(RefCell::new(res)));
        }
        
        // breadth first search to get to right depth
        let mut queue = VecDeque::new();
        
        queue.push_back(State {
            d,
            node: root.clone(),
        });
        
        while let Some(state) = queue.pop_front() {
            
            // update tree if d = 2
            if state.d == 2 {
                let mut node = state.node.borrow_mut();
                
                node.left = Some(Rc::new(RefCell::new(TreeNode {
                    val: v,
                    left: node.left.clone(),
                    right: None,
                })));
                node.right = Some(Rc::new(RefCell::new(TreeNode {
                    val: v,
                    left: None,
                    right: node.right.clone(),
                })));

                continue;
            }
        
            // go deeper otherwise
            let node = state.node.borrow();
            
            if let Some(left_node) = node.left.clone() {
                queue.push_back(State {
                    d: state.d - 1,
                    node: left_node
                });
            }
            if let Some(right_node) = node.right.clone() {
                queue.push_back(State {
                    d: state.d - 1,
                    node: right_node
                });
            }
        }
        
        Some(root)
    }
}
