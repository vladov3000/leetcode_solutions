struct Result {
    int sum;
    int count;
    int equal;
};

static Result helper(TreeNode* node) {
    if (node == nullptr)
        return (Result) { .sum = 0, .count = 0, .equal = 0 };

    Result left   = helper(node->left);
    Result right  = helper(node->right);
    Result result = { 
        .sum   = left.sum   + right.sum   + node->val, 
        .count = left.count + right.count + 1,
        .equal = left.equal + right.equal,
    };

    if (result.sum / result.count == node->val)
        result.equal++;

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
    int averageOfSubtree(TreeNode* root) {
        return helper(root).equal;
    }
};
