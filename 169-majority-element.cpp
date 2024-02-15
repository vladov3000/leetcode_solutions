#include <span>

class Solution {
public:
/*
    int majorityElement(span<int> numbers) {
        unordered_map<int, int> frequencies;
        for (int number : numbers) {
            frequencies[number]++;
        }

        for (const auto& entry : frequencies) {
            if (entry.second > numbers.size() / 2) {
                return entry.first;
            }
        }

        return 0;
    }
*/

    int majorityElement(span<int> numbers) {
        int candidate = numbers[0];
        int count     = 1;
        for (int number : numbers.subspan(1)) {
            if (number == candidate) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    candidate = number;
                    count     = 1;
                }
            }
        }
        return candidate;
    }
};
