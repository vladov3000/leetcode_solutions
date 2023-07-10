static int helper(int* cookies, int size, int* children, int k) {
    if (size == 0) {
        int result = INT_MIN;

        for (int i = 0; i < k; i++)
            result = max(result, children[i]);

        return result;
    }

    int result = INT_MAX;

    for (int i = 0; i < k; i++) {
        children[i] += cookies[0];

        result = min(
            result, 
            helper(&cookies[1], size - 1, children, k)
        );

        children[i] -= cookies[0];
    }

    return result;
}

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k);
        return helper(
            cookies.data(), 
            cookies.size(),
            children.data(),
            children.size()
        );
    }
};
