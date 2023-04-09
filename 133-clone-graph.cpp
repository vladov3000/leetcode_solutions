/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

static Node* helper(
    unordered_map<Node*, Node*>& nodes, 
    Node* node
) {
    auto entry = nodes.find(node);
    if (entry != nodes.cend())
        return entry->second;

    nodes[node] = new Node(node->val);
    for (Node* next : node->neighbors)
        nodes[node]->neighbors.push_back(helper(nodes, next));
    return nodes[node];
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> nodes;
        return helper(nodes, node);
    }
};
