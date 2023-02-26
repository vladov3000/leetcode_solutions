class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& times) {
        static_assert(sizeof(int) >= 4);

        unordered_map<int, int> counts;
        int result = 0;

        for (int time : times) {
            time = time % 60;
            int inverse = (60 - time) % 60;

            if (counts.find(inverse) != counts.cend())
                result += counts.at(inverse);

            counts[time]++;
        }

        return result;
    }
};
