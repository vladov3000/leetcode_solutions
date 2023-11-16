class MovingAverage {
public:
    MovingAverage(int size) : sum(0), size(size) {}
    
    double next(int value) {
        if (window.size() == size) {
            sum -= window.front();
            window.pop();
        }
        sum += value;
        window.push(value);
        return (double) sum / window.size();
    }

private:
    queue<int> window;
    int        sum;
    int        size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
