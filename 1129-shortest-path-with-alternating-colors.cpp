typedef unordered_map<int, vector<int>> Graph;

static Graph edges_to_graph(const vector<vector<int>>& edges) {
    Graph result;
    for (const auto& edge : edges)
        result[edge[0]].push_back(edge[1]);
    return result;
}

enum Color {
    RED,
    BLUE,
};

struct State {
    Color color;
    int   depth;
    int   node;

    State(Color color, int depth, int node) 
        : color(color), depth(depth), node(node) {}
};

static bool find_and_insert(unordered_set<int>& seen, int node) {
    if (seen.find(node) != seen.cend())
        return false;
    seen.insert(node);
    return true;
}

class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n, 
        const vector<vector<int>>& red_edges, 
        const vector<vector<int>>& blue_edges
    ) {
        Graph red_graph = edges_to_graph(red_edges);
        Graph blue_graph = edges_to_graph(blue_edges);

        queue<State> states;
        states.emplace(RED, 0, 0);
        states.emplace(BLUE, 0, 0);

        vector<int> result(n, -1);
        result[0] = 0;

        unordered_set<int> seen_red;
        unordered_set<int> seen_blue;

        while (!states.empty()) {
            State state = states.front();
            states.pop();

            if (result[state.node] == -1 || state.depth < result[state.node])
                result[state.node] = state.depth;

            if (state.color == RED 
                && blue_graph.find(state.node) != blue_graph.cend()
                && find_and_insert(seen_red, state.node))
                    for (int next : blue_graph.at(state.node))
                        states.emplace(BLUE, state.depth + 1, next);

            if (state.color == BLUE && 
                red_graph.find(state.node) != red_graph.cend()
                && find_and_insert(seen_blue, state.node))
                    for (int next : red_graph.at(state.node))
                        states.emplace(RED, state.depth + 1, next);
        }

        return result;
    }
};
