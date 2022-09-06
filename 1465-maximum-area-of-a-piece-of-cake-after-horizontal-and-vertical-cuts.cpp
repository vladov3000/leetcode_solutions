static const int answer_modulo = 1000000007;

static long long max_delta(vector<int>& a, int dim) {
    sort(a.begin(), a.end());
    
    int result = a[0];
    for (int i = 1; i < a.size(); i++)
        result = max(result, a[i] - a[i - 1]);
    result = max(result, dim - a.back());
    
    return result % answer_modulo;
}

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontal, vector<int>& vertical) {
        long long max_dx = max_delta(horizontal, h);
        long long max_dy = max_delta(vertical, w);
        long long result = (max_dx * max_dy) % answer_modulo;
        return result;
    }
};
