/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func preorder(root *Node) []int {
    if root == nil {
        return []int{}
    }
    
    res := []int{ root.Val }
    
    for _, child := range root.Children {
        res = append(res, preorder(child)...)
    }
    
    return res
}
