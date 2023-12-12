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
struct Result {
    long   count;
    long   sum;
    double max_average;
};

static Result helper(TreeNode* node) {
    if (node == nullptr)
        return (Result) {};

    Result left  = helper(node->left);
    Result right = helper(node->right);

    Result result;
    result.count       = left.count + right.count + 1;
    result.sum         = left.sum + right.sum + node->val;
    result.max_average = (double) result.sum / result.count;
    result.max_average = max(result.max_average, left.max_average);
    result.max_average = max(result.max_average, right.max_average);
    return result;
}

class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        return helper(root).max_average;
    }
};
