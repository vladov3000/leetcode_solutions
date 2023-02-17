static int helper(TreeNode* node, int base) {
    if (node == nullptr)
        return INT_MAX;
    
    int result = abs(node->val - base);
    result = min(result, helper(node->left, base));
    result = min(result, helper(node->right, base));
    return result;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* node) {
        if (node == nullptr)
            return INT_MAX;
        
        int result = helper(node->left, node->val);
        result = min(result, helper(node->right, node->val));
        result = min(result, minDiffInBST(node->left));
        result = min(result, minDiffInBST(node->right));
        return result;
    }
};
