class Solution {
public:
    vector<long long> maximumEvenSplit(long long final_sum) {
        if (final_sum & 1)
            return move(vector<long long>());
        
        vector<long long> result;
        long long sum = 0;
        
        for (long long i = 2; 
             sum + i < final_sum && i < final_sum - sum - i; 
             i += 2) {
            
            result.push_back(i);
            sum += i;
        }
        
        result.push_back(final_sum - sum);
        return move(result);
    }
};
