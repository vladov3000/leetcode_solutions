#include <span>

class Solution {
public:
/* O(n) time O(n) space
    vector<int> findErrorNums(span<int> numbers) {
        unordered_map<int, int> counts;
        for (int number : numbers) {
            counts[number]++;
        }

        vector<int> result(2);
        for (int i = 1; i <= numbers.size(); i++) {
            const auto entry = counts.find(i);
            if (entry == counts.cend()) {
                result[1] = i;
            } else if (entry->second == 2) {
                result[0] = i;
            }
        }
        return result;
    }
*/

    vector<int> findErrorNums(span<int> numbers) {
        vector<int> result(2);
        for (int i = 0; i < numbers.size(); i++) {
            int index = abs(numbers[i]) - 1;
            if (numbers[index] < 0) {
                result[0] = index + 1;
            } else {
                numbers[index] = -numbers[index];
            }
        }

        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] > 0) {
                result[1] = i + 1;
                break;
            }
        }

        return result;
    }
};
