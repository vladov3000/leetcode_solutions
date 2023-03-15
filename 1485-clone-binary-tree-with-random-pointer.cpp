/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

static NodeCopy* helper(Node* root, unordered_map<Node*, NodeCopy*>& computed) {
    if (root == nullptr)
        return nullptr;

    auto maybe_result = computed.find(root);
    if (maybe_result != computed.cend())
        return maybe_result->second;

    NodeCopy* result = new NodeCopy(root->val);
    computed.emplace(root, result);
    result->left = helper(root->left, computed);
    result->right = helper(root->right, computed);
    result->random = helper(root->random, computed);
    computed.emplace(root, result);
    return result;
}

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> computed;
        return helper(root, computed);
    }
};
