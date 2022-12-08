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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int result = 0;

        std::stack<const TreeNode*> todo;
        todo.push(root);

        while (!todo.empty()) {
            const TreeNode* cur = todo.top();
            todo.pop();

            if (low <= cur->val && cur->val <= high)
                result += cur->val;
            if (cur->left != nullptr)
                todo.push(cur->left);
            if (cur->right != nullptr)
                todo.push(cur->right);
        }

        return result;
    }
};
