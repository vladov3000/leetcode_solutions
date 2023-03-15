static int helper(TreeNode* node, int base) {
    if (node == nullptr)
        return 0;

    int new_base = base * 10 + node->val;

    if (node->left == nullptr && node->right == nullptr)
        return new_base;
        
    return helper(node->left, new_base) + helper(node->right, new_base);
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
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};
