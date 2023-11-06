class Solution {
public:
    vector<int> majorityElement(const vector<int>& numbers) {
        if (numbers.size() < 3) {
            return numbers;
        }

        int most_common_elements[2] = {};
        int most_common_counts[2]   = {};

        for (int number : numbers) {
            if (most_common_counts[0] == 0) {
                most_common_elements[0] = number;
                most_common_counts[0]   = 1;
            } else if (most_common_counts[1] == 0) {
                most_common_elements[1] = number;
                most_common_counts[1]   = 1;
            } else if (number == most_common_elements[0]) {
                most_common_counts[0]++;
            } else if (number == most_common_elements[1]) {
                most_common_counts[1]++;
            } else {
                most_common_counts[0]--;
                most_common_counts[1]--;
            }
        }

        vector<int> result;
        for (int i = 0; i < 2; i++) {
            auto actual_count = count(
                numbers.cbegin(), 
                numbers.cend(), 
                most_common_elements[i]
            );
            if (actual_count > numbers.size() / 3) {
                result.push_back(most_common_elements[i]);
            }
        }

        return result;
    }
};
