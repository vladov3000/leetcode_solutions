
static int helper(
    const TreeNode* root, 
    unordered_map<const TreeNode*, int>& left, 
    unordered_map<const TreeNode*, int>& right
) {
    if (root == nullptr)
        return 0;

    int result = max(helper(root->left, left, right), 
                     helper(root->right, left, right));
    
    left[root]  = root->left == nullptr ? 0 : (right[root->left] + 1);
    right[root] = root->right == nullptr ? 0 : (left[root->right] + 1);

    return max(result, max(left[root], right[root]));
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
    int longestZigZag(const TreeNode* root) {
        unordered_map<const TreeNode*, int> left, right;
        return helper(root, left, right);
    }
};
