struct Point {
    int x, y;
};

template <>
struct hash<Point> {
    size_t operator()(Point point) const {
        return hash<int>()(point.x) * 31 + hash<int>()(point.y);
    }
};

bool operator==(Point left, Point right) {
    return left.x == right.x && left.y == right.y;
}

class Solution {
public:
    bool isPathCrossing(string_view path) {
        Point                current = {};
        unordered_set<Point> visited;
        visited.insert(current);

        for (char c : path) {
            switch (c) {
                case 'N': current.y++; break;
                case 'S': current.y--; break;
                case 'E': current.x++; break;
                case 'W': current.x--; break;
            }

            if (visited.contains(current))
                return true;
            else
                visited.insert(current);
        }

        return false;
    }
};
