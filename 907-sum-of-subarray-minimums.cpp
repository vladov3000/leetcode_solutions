#include <span>

struct Pair {
    int number;
    int count;

    Pair(int number, int count) : number(number), count(count) {}
};

class Solution {
public:
/* O(n^2) time O(1) space
    int sumSubarrayMins(span<int> numbers) {
        int n      = numbers.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            int minimum = numbers[i];
            result += minimum;
            for (int j = i + 1; j < n; j++) {
                minimum = min(minimum, numbers[j]);
                result += minimum;
                result %= 1'000'000'007;
            }
        }
        return result;
    }
*/
    // O(n) time O(n) space
    int sumSubarrayMins(span<int> numbers) {
        int n = numbers.size();
        stack<Pair> pairs;

        vector<int> left(n);
        for (int i = 0; i < n; i++) {
            int count = 1;

            while (!pairs.empty() && pairs.top().number > numbers[i]) {
                count += pairs.top().count;
                pairs.pop();
            }

            pairs.emplace(numbers[i], count);
            left[i] = count;
            cout << left[i] << ' ';
        }
        cout << '\n';

        stack<Pair>().swap(pairs);

        vector<int> right(n);
        for (int i = n - 1; i >= 0; i--) {
            int count = 1;

            while (!pairs.empty() && pairs.top().number >= numbers[i]) {
                count += pairs.top().count;
                pairs.pop();
            }

            pairs.emplace(numbers[i], count);
            right[i] = count;
            cout << right[i] << ' ';
        }
        cout << '\n';

        long result = 0;
        for (int i = 0; i < numbers.size(); i++) {
            long subarrays = numbers[i];
            subarrays      = subarrays * left[i]  % 1'000'000'007;
            subarrays      = subarrays * right[i] % 1'000'000'007;
            result         = (result + subarrays) % 1'000'000'007;
        }
        return result;
    }
};
