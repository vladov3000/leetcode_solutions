#include <span>

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
    vector<TreeNode*> delNodes(TreeNode* root, span<int> to_delete) {
        vector<TreeNode*>  result;
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());

        if (root == nullptr)
            return result;

        if (!to_delete_set.contains(root->val))
            result.push_back(root);

        delNodes(root, to_delete_set, result);
        return result;
    }

    void delNodes(
        TreeNode*                 root,
        const unordered_set<int>& to_delete,
        vector<TreeNode*>&        result
    ) {
        for (int i = 0; i < 2; i++) {
            TreeNode*& child = i == 0 ? root->left : root->right;
            if (child != nullptr) {
                delNodes(child, to_delete, result);
                if (to_delete.contains(child->val))
                    child = nullptr;
                else if (to_delete.contains(root->val))
                    result.push_back(child);
            }
        }
    }
};
