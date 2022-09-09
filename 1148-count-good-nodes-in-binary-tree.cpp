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
static int helper(TreeNode* root, int path_max) {
    if (root == NULL)
        return 0;
    
    int new_path_max = max(path_max, root->val);
    return (path_max <= root->val) + 
        helper(root->left, new_path_max) +
        helper(root->right, new_path_max);
}

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return helper(root, -10001);
    }
};
