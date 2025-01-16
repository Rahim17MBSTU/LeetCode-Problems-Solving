class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int xorValue = 0;
        for(auto u:nums2) xorValue ^= u;
        if(n % 2 == 0 && m % 2 == 0) return 0;
        if(n % 2 == 1 && m % 2 == 0) return xorValue;
        int ans = 0;
        for(auto u:nums1){
            int x = xorValue ^ u;
            ans ^= x;
        }
        return ans;
    }
};