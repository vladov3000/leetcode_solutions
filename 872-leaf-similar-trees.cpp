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
static bool is_leaf(const TreeNode* node) {
    return node->left == nullptr && node->right == nullptr;
}

class LeafIterator {
public:
    // LeafIterator is only valid while `root`
    // and all of its children are still valid.
    LeafIterator(const TreeNode* root);

    // Returns next leaf value or nullptr if there are none left.
    // Assumes `root` passed into constructor or any of its
    // children have not been mutated since LeafIterator
    // was constructed.
    const TreeNode* next();

    bool done();

private:
    std::stack<const TreeNode*> nodes;
};


LeafIterator::LeafIterator(const TreeNode* root) {
    nodes.push(root);
}

const TreeNode* LeafIterator::next() {
    if (nodes.empty())
        return nullptr;

    const TreeNode* result = nodes.top();
    nodes.pop();

    while (!is_leaf(result)) {
        if (result->left != nullptr) {
            if (result->right != nullptr)
                nodes.push(result->right);
            result = result->left;
        } 
        
        else if (result->right != nullptr)
            result = result->right;
    }

    return result;
}

bool LeafIterator::done() {
    return nodes.empty();
}

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        LeafIterator it1(root1);
        LeafIterator it2(root2);

        while (!it1.done() && !it2.done())
            if (it1.next()->val != it2.next()->val)
                return false;
        return it1.done() && it2.done();
    }
};
