struct Compare {
    bool operator()(pair<int, int> x, pair<int, int> y) {
        return x.second < y.second; 
    }
};

class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (int i : nums)
            freqs[i]++;
        
        priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>, 
            Compare
        > heap(freqs.begin(), freqs.end());

        vector<int> result;
        for (int i = 0; i < k; i++)
            result.push_back(heap.top().first), heap.pop();
        return result;
    }
};
