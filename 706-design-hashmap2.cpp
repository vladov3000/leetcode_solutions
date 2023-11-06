class MyHashMap {
public:
    MyHashMap() : buckets(4096) {}
    
    void put(int key, int value) {
        list<Node>& bucket = buckets[key % buckets.size()];
        for (auto& entry : bucket) {
            if (entry.key == key) {
                entry.value = value;
                return;
            }
        }
        bucket.emplace(bucket.cend(), key, value);
    }
    
    int get(int key) const {
        const list<Node>& bucket = buckets[key % buckets.size()];
        for (auto& entry : bucket) {
            if (entry.key == key) {
                return entry.value;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        list<Node>& bucket = buckets[key % buckets.size()];
        auto        entry  = bucket.cbegin();
        while (entry != bucket.cend()) {
            if (entry->key == key) {
                bucket.erase(entry);
                return;
            }
            entry++;
        }
    }

private:
    struct Node {
        int        key;
        int        value;

        Node(int key, int value) : key(key), value(value) {}
    };

    vector<list<Node>> buckets;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
