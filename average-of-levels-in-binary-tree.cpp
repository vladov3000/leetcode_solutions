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

struct State {
    TreeNode* node;
    int       level; 
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<State> todo;
        todo.push({root, 0});
        
        vector<double> results;
        int    level  = 0;
        double result = 0;
        int    count  = 0;
        
        while (!todo.empty()) {
            auto cur = todo.front();
            todo.pop();
            
            if (level != cur.level) {
                results.push_back(result / count);
                level  = cur.level;
                result = 0;
                count  = 0;
            }
            
            result += cur.node->val;
            count++;
            
            if (cur.node->left) todo.push({ cur.node->left, cur.level + 1});
            if (cur.node->right) todo.push({ cur.node->right, cur.level + 1});
        }
        
        results.push_back(result / count);
        return move(results);
    }
};
