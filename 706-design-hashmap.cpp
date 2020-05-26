// Runtime: 228 ms, faster than 32.88% of C++ online submissions for Design HashMap.
// Memory Usage: 46.5 MB, less than 46.43% of C++ online submissions for Design HashMap.


class MyHashMap {
    
private:
    static const int NUM_BINS = 100;
    deque<pair<int,int>> bins[NUM_BINS];
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        remove(key);
        bins[key % NUM_BINS].push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        deque<pair<int,int>>& bin = bins[key % NUM_BINS];
        
        for (int i = 0; i < bin.size(); i++) {
            if (bin[i].first == key) return bin[i].second;
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        deque<pair<int,int>>& bin = bins[key % NUM_BINS];
        if (get(key) == -1) return;
        
        int idx = 0;
        while (bin[idx].first != key) idx ++;
        bin.erase(bin.begin() + idx);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
