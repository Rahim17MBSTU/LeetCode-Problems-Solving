class Solution {
public:
    int solve(int i ,int sum ,vector<int> &nums,vector<vector<int>>&dp,int target,int totalSum){
        if(i == nums.size()){
            if(target == sum)return 1;
            else return 0;
        }
        if(dp[i][sum+totalSum] != -1){
            return dp[i][sum+totalSum];
        }
        int ans = 0;
        ans += solve(i+1,sum+ nums[i],nums,dp,target,totalSum) + solve(i+1,sum - nums[i] , nums,dp,target,totalSum);
        return dp[i][sum+totalSum] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(auto u:nums) totalSum += u;
        vector<vector<int>> dp(nums.size()+10,vector<int>(2*totalSum+10 , -1));
        return solve(0,0,nums,dp,target,totalSum);
    }
};