class BrowserHistory {
public:
    BrowserHistory(string homepage) : location(0) {
        visited.emplace_back(move(homepage));
    }
    
    void visit(string url) {
        visited.resize(location + 1);
        visited.emplace_back(move(url));
        location++;
    }
    
    string back(int steps) {
        location = max(0, location - steps);
        return visited[location];
    }
    
    string forward(int steps) {
        location = min(static_cast<int>(visited.size()) - 1, location + steps);
        return visited[location];
    }
private:
    int location;
    string homepage;
    vector<string> visited;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
