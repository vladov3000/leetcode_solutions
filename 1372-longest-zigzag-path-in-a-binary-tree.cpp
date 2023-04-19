struct Result {
    int left;
    int right;
    int best;
};

static Result helper(const TreeNode* root) {
    if (root == nullptr)
        return (Result) { .left = 0, .right = 0, .best = 0 };

    Result left = helper(root->left);
    Result right = helper(root->right);
    int best = max(left.best, right.best);

    return (Result) {
        .left = left.right + 1,
        .right = right.left + 1,
        .best = max(best, max(left.right, right.left)),
    };
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
        return helper(root).best;
    }
};
