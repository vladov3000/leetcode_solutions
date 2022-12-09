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
    int max_diff;
    int min_val;
    int max_val;
};

static Result helper(TreeNode* root) {
    if (root == nullptr)
        return (Result) { 
            .max_diff = INT_MIN, 
            .min_val = INT_MAX,
            .max_val = INT_MIN, 
        };

    Result left = helper(root->left);
    Result right = helper(root->right);

    Result result;
    result.min_val  = min(root->val, min(left.min_val, right.min_val));
    result.max_val  = max(root->val, max(left.max_val, right.max_val));
    result.max_diff = max(right.max_diff, left.max_diff);
    if (result.min_val < INT_MAX)
        result.max_diff = max(result.max_diff, root->val - result.min_val);
    if (result.max_val > INT_MIN)
        result.max_diff = max(result.max_diff, result.max_val - root->val);
    // cout << root->val << ' ' << result.min_val << ' ' << result.max_diff << '\n';
    return result;
}

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return helper(root).max_diff;
    }
};
