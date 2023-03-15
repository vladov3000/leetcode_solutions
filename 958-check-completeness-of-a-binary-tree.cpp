

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
    bool isCompleteTree(TreeNode* root) {

        struct State {
            TreeNode* node;
            int       level;

            State(TreeNode* node, int level) : node(node), level(level) {}
        };

        deque<State> states;
        states.emplace_back(root, 1);

        while (!states.empty()) {
            State state = states.front();
            states.pop_front();

            if (state.node == nullptr)
                break;

            states.emplace_back(state.node->left, state.level + 1);
            states.emplace_back(state.node->right, state.level + 1);
        }

        for (State state : states)
            if (state.node != nullptr)
                return false;

        return true;
    }
};
