class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<vector<int>>result;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0 , j = 0;
        while(1){
            if(i<n && j < m && nums1[i][0] < nums2[j][0]){
                result.push_back({ nums1[i][0],nums1[i][1]});
                i++;
            }
             if(i<n && j <m && nums1[i][0] > nums2[j][0]){
                result.push_back({nums2[j][0],nums2[j][1]});
                j++;
            }
            if(i<n && j < m && nums1[i][0] == nums2[j][0]){
                result.push_back({nums2[j][0], nums1[i][1]+nums2[j][1]});
                i++;
                j++;
            }
             if(i>=n && j < m ){
                result.push_back({nums2[j][0],nums2[j][1]});
                j++;
            }
             if(i<n && j >= m ){
                result.push_back({nums1[i][0],nums1[i][1]});
                i++;
            }

            if(i >= n && j >= m)break;
        }
        return result;
        
    }
};