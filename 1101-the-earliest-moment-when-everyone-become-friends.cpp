// Comparison function to pass to std::sort that will sort
// by timestamps ascending.
static bool timestamps_ascending(const vector<int>& x,
                          const vector<int>& y) {
    return x[0] < y[0];
}

// Disjoint set
// graph[i] == -1 => -1 is the representative of a set
// graph[i] == x  => x is the parent of i
static int disjoint_set[100];
static int disjoint_set_count;

// Returns representative of set x is in
static int find(int child) {
    if (disjoint_set[child] == -1)
        return child;

    int parent = child;
    while (disjoint_set[parent] != -1)
        parent = disjoint_set[parent];

    // Cache parent of child to reduce height of tree
    disjoint_set[child] = parent;
    return parent;
}

// Take union of 2 sets in disjoint set
static void combine(int x, int y) {
    int x_rep = find(x);
    int y_rep = find(y);

    if (x_rep == y_rep)
        return;

    disjoint_set[x_rep] = y_rep;
    disjoint_set_count--;
}

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        // We start off with n disjoint sets
        memset(disjoint_set, -1, n * sizeof(int));
        disjoint_set_count = n;

        sort(logs.begin(), logs.end(), timestamps_ascending);

        for (const auto& log : logs) {
            combine(log[1], log[2]);

            if (disjoint_set_count == 1)
                return log[0];
        }

        return -1;
    }
};
