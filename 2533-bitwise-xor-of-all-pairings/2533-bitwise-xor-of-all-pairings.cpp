class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int xorValue1 = 0, xorValue2 = 0;
        for(auto u:nums1) xorValue1 ^= u;
        for(auto u:nums2) xorValue2 ^= u;
        if(n % 2 == 0 && m % 2 == 0) return 0;
        if(n % 2 == 1 && m % 2 == 0) return xorValue2;
        if(n % 2 == 0 && m % 2 == 1) return xorValue1;
        else  return (xorValue1 ^ xorValue2);
          
    }
};