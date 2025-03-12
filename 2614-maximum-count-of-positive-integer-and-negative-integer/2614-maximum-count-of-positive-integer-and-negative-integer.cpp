class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        int p = nums.size() - (upper_bound(nums.begin(),nums.end(),0)-nums.begin());
        return max(p,n);
    }
};