class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) {
        pushed.push(x);
    }
    
    int pop() {
        reverse();
        int result = reversed.top();
        reversed.pop();
        return result;
    }
    
    int peek() {
        reverse();
        return reversed.top();
    }
    
    bool empty() {
        return pushed.empty() && reversed.empty();
    }

private:
    void reverse() {
        if (reversed.empty()) {
            while (!pushed.empty()) {
                reversed.push(pushed.top());
                pushed.pop();
            }
        }
    }

    stack<int> pushed;
    stack<int> reversed;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
