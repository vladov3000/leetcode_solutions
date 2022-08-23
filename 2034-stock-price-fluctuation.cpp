static_assert(sizeof(int) * CHAR_BIT >= 32);

struct Record {
    int timestamp;
    int price;
};

class StockPrice {
public:
    StockPrice() : current_idx(0) {
        
    }
    
    void update(int timestamp, int price) {
        if (prices.find(timestamp) != prices.end())
            if (--counts.at(prices.at(timestamp)) == 0)
                counts.erase(prices.at(timestamp));
        
        prices[timestamp] = price;
        counts.try_emplace(price, 0).first->second++;
        current_idx = max(current_idx, timestamp);
    }
    
    int current() {
        return prices.at(current_idx);
    }
    
    int maximum() {
        return counts.rbegin()->first;
    }
    
    int minimum() {
        return counts.begin()->first;
    }
    
private:
    unordered_map<int, int> prices;
    map<int, int> counts;
    int current_idx;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
