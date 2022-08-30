static int time_diff(int x, int y) {
    int dt = x - y;
    return dt < 24 * 60 / 2 ? dt : 24 * 60 - dt;
}

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        
        for (const auto& s : timePoints)
            times.push_back((s[0] * 10 + s[1]) * 60 + s[3] * 10 + s[4]);
                         
        sort(times.begin(), times.end());
                         
        int result = time_diff(times.back(), times.front());
        
        for (auto i = 1; i < times.size(); i++)
            result = min(result, time_diff(times[i], times[i - 1]));
        
        return result;
    }
};
