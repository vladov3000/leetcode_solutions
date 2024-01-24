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
static int helper(TreeNode* node, int counts[9]) {
    if (node == nullptr) {
        return 0;
    }

    int result;
    counts[node->val - 1]++;

    if (node->left == nullptr && node->right == nullptr) {
        bool seen_odd = false;
        for (int i = 0; i < 9; i++) {
            int count = counts[i];
            if (count & 1) {
                if (seen_odd) {
                    result = 0;
                    goto END;
                } else {
                    seen_odd = true;
                }
            }
        }
        result = 1;
    } else {    
        int left  = helper(node->left, counts);
        int right = helper(node->right, counts);
        result    = left + right;
    }

    END:
    counts[node->val - 1]--;
    return result;
}

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* node) {
        int counts[9] = {};
        return helper(node, counts);
    }
};
