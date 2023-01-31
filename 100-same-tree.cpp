struct TreeNodePair {
    TreeNode* first;
    TreeNode* second;

    TreeNodePair(TreeNode* firstArg, TreeNode* secondArg) 
        : first(firstArg), second(secondArg) {}
};

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNodePair> todo;
        todo.emplace(p, q);

        while (!todo.empty()) {
            TreeNodePair cur = todo.top();
            todo.pop();

            if ((cur.first == nullptr) != (cur.second == nullptr))
                return false;

            if (cur.first == nullptr)
                continue;

            if (cur.first->val != cur.second->val)
                return false;

            todo.emplace(cur.first->left, cur.second->left);
            todo.emplace(cur.first->right, cur.second->right);
        }

        return true;
    }
};
