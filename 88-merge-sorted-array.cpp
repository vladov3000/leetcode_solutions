class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /* First Solution:
            // Runtime: 4 ms, faster than 82.37% of C++ 
            online submissions for Merge Sorted Array.
            // Memory Usage: 9.3 MB, less than 6.52% of 
            C++ online submissions for Merge Sorted Array.

        vector<int> out;
        
        int a = 0;
        int b = 0;
        while (a < m || b < n) {
            if (a < m && (b >= n || nums1[a] < nums2[b])) {
                out.push_back(nums1[a]);
                a++;
            } else if (b < n) {
                out.push_back(nums2[b]);
                b++;
            }
            
            // printf("%d %d\n", a, b);
        }
        for (int i = 0; i < nums1.size() - n - m; i++) {
            out.push_back(0);
        }
        
        nums1 = out;
        */
        
        /* 2nd Solution (in place) */
        int i=m-1, j=n-1, k=m+n-1;
        while (i >= 0 && j >= 0) {
            
            // printf("%d %d %d\n", i, j, k);
            
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        while (i >= 0) nums1[k--] = nums1[i--];
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};
