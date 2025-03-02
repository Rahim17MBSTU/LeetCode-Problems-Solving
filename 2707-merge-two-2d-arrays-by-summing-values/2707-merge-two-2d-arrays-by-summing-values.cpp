class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;
        for(auto u:nums1) mp[u[0]]+=u[1];
        for(auto u:nums2) mp[u[0]]+=u[1];
        vector<vector<int>> result;
        int cnt = 0;
        for(auto u:mp){
            result.push_back({u.first,u.second});
        }
        return result;
    }
};