static int sort_by_second_desceding(const vector<int>& x, const vector<int>& y) {
    return x[1] > y[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& box_types, int truck_size) {
        sort(box_types.begin(), box_types.end(), sort_by_second_desceding);
        
        int result = 0;
        
        for (const auto& box_type : box_types) {
            int boxes = min(truck_size, box_type[0]);
            result += boxes * box_type[1];
            truck_size -= boxes;
            if (truck_size <= 0)
                break;
        }
        
        return result;
    }
};
