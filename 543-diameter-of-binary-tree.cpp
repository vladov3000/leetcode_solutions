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
typedef struct {
    int length;
    int result;
} Result;

static Result helper(TreeNode* node) {
    if (node == nullptr) {
        return Result {};
    }

    Result left  = helper(node->left);
    Result right = helper(node->right);
    return (Result) {
        .length = max(left.length, right.length) + 1,
        .result = max(max(left.result, right.result), left.length + right.length),
    };
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).result;
    }
};
