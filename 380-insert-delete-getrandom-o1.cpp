class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int value) {
        if (value_to_index.contains(value)) {
            return false;
        } else {
            value_to_index.emplace(value, values.size());
            values.push_back(value);
            return true;
        }
    }
    
    bool remove(int value) {
        const auto entry = value_to_index.find(value);
        if (entry == value_to_index.cend()) {
            return false;
        } else {
            int index = entry->second;
            value_to_index[values.back()] = index;
            values[index] = values.back();
            values.pop_back();
            value_to_index.erase(value);
            return true;
        }
    }
    
    int getRandom() {
        return values[rand() % values.size()];
    }

private:
    vector<int>              values;
    unordered_map<int, int>  value_to_index;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
