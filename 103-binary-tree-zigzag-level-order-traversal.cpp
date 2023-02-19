struct State {
    TreeNode* node;
    int depth;

    State(TreeNode* node, int depth) : node(node), depth(depth) {}
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        queue<State> states;
        states.emplace(root, 0);

        while (!states.empty()) {
            State state = states.front();
            states.pop();

            if (state.node == nullptr)
                continue;
                
            if (result.size() == state.depth)
                result.emplace_back();
            
            result[state.depth].push_back(state.node->val);

            states.emplace(state.node->left, state.depth + 1);
            states.emplace(state.node->right, state.depth + 1);
        }

        for (int i = 0; i < result.size(); i++)
            if (i & 1)
                reverse(result[i].begin(), result[i].end());

        return result;
    }
};
