class Solution {
public:
    vector<int> anagramMappings(
        const vector<int>& nums1, 
        const vector<int>& nums2
    ) {
        unordered_map<int, vector<int>> mapping;

        for (int i = 0; i < nums2.size(); i++)
            mapping[nums2[i]].push_back(i);
        
        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            result[i] = mapping[nums1[i]].back();
            mapping[nums1[i]].pop_back();
        }

        return result;
    }
};
