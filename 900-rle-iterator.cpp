class RLEIterator {
public:
    RLEIterator(const vector<int>& encoding) noexcept {
        _it    = encoding.cbegin() + 1;
        _end   = encoding.cend();
        _count = encoding.front();
    }
    
    int next(int n) noexcept {
        if (_it == _end)
            return -1;

        while (_count < n)
            if (n -= _count, next_elements())
                return -1;

        _count -= n;
        if (_count)
            return *_it;

        int result = *_it;
        next_elements();
        return result;
    }

private:
    bool next_elements() {
        _it++;
        if (_it == _end)
            return true;
        _count = *_it;
        _it++;
        return false;
    }

    vector<int>::const_iterator _it;
    vector<int>::const_iterator _end;
    int _count;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
