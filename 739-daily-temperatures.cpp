#include <span>

class Solution {
public:
    /* O(n^2) time O(n) space
    vector<int> dailyTemperatures(span<int> temperatures) {
        vector<int> answer(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            for (int j = i + 1; j < temperatures.size(); j++) {
                if (temperatures[j] > temperatures[i]) {
                    answer[i] = j - i;
                    break;
                }
            }
        }

        return answer;
    }
    */

    vector<int> dailyTemperatures(span<int> temperatures) {
        stack<int>  maxes({ 0 });
        vector<int> answer(temperatures.size());

        for (int i = 1; i < temperatures.size(); i++) {
            while (!maxes.empty() && temperatures[i] > temperatures[maxes.top()]) {
                answer[maxes.top()] = i - maxes.top();
                maxes.pop();
            }
            maxes.push(i);
        }

        return answer;
    }
};
