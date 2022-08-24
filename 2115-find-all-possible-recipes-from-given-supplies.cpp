class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, 
                                  vector<vector<string>>& ingredients, 
                                  vector<string>& supplies) {
        
        unordered_map<string_view, vector<string_view>> graph;
        unordered_map<string_view, int> in_degrees;
        
        for (auto i = 0; i < recipes.size(); i++) {
            for (const auto& ingredient : ingredients[i])
                graph[ingredient].push_back(recipes[i]);
            in_degrees[recipes[i]] += ingredients[i].size();
        }
        
        deque<string_view> todo(supplies.cbegin(), supplies.cend());
        vector<string> result;
        
        while (!todo.empty()) {
            const auto front = todo.front();
            todo.pop_front();
            
            if (graph.find(front) == graph.end())
                continue;
            
            for (const auto& recipe : graph.at(front))
                if (in_degrees[recipe] && --in_degrees[recipe] == 0) {
                    todo.push_back(recipe);
                    result.push_back(std::move(string(recipe)));
                }
        }
        
        return result;
    }
};
