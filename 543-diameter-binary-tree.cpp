//Runtime: 4 ms, faster than 99.19% of C++ online submissions for Diameter of Binary Tree.
//Memory Usage: 20.9 MB, less than 11.11% of C++ online submissions for Diameter of Binary Tree.

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
private:
    int helper(TreeNode* cur, int& height) {
        if (cur == NULL) return 0;
        // printf("%d\n", height);
        height ++;
        
        int rh = 0;
        int lh = 0;
        int d = helper(cur->left, rh);
        d = max(d, helper(cur->right, lh));
        height = max(rh, lh) + 1;
        
        return max(rh + lh + 1, d);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int h = 0;
        return helper(root, h) - 1;
    }
};
