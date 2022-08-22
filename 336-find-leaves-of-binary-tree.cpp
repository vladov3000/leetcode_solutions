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
    int helper(TreeNode* root, vector<vector<int>>& out) {
        if (root == NULL)
            return 0;
        
        int left = helper(root->left, out);
        int right = helper(root->right, out);
        int level = max(left, right) + 1;
        
        if (out.size() < level) {
            out.reserve(level);
            out.insert(out.end(), level - out.size(), std::move(vector<int>()));
        }
        
        out[level - 1].push_back(root->val);
        return level;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        helper(root, result);
        return result;
    }
};
