class Solution {
public:
    vector<bool> kidsWithCandies(
        const vector<int>& candies, 
        int extra_candies
    ) {
        int max_candy = 0;
        for (int candy : candies)
            max_candy = max(max_candy, candy);
        
        vector<bool> result(candies.size());
        for (int i = 0; i < candies.size(); i++)
            if (candies[i] + extra_candies >= max_candy)
                result[i] = true;

        return result;
    }
};
