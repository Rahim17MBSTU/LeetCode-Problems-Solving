class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long int total_sum = 0;
        int n = nums.size();
        for(auto u:nums){
            total_sum = (u + total_sum)%p;
        }
        int rem = total_sum % p;
        if(rem == 0) return 0;

        unordered_map<int,int>mp;
        mp[0] = - 1;
        int res = n, currSumMod = 0;
        for(int i=0;i<n;i++){
            currSumMod = (currSumMod + nums[i]) % p;
            int needSum = (currSumMod - rem + p ) % p;
            mp[currSumMod] = i;
            if(mp.find(needSum) != mp.end()){
                res = min(res,i-mp[needSum]);
            }
            
        }
        return res == n ? -1 : res;
    }
};