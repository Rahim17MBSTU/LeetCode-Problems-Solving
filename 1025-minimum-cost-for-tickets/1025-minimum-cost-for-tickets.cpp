class Solution {
public:
    int solve(int i , vector<int>&days, vector<int>& costs,vector<int>&dp){
        if(i>= days.size())return 0;
        int value = days[i];
        if(dp[i] !=-1 )return dp[i];
        int indx0 = lower_bound(days.begin(),days.end(),value+1)-days.begin();
        int indx = lower_bound(days.begin(),days.end(),value+7)-days.begin();
        int indx1 = lower_bound(days.begin(),days.end(),value+30)-days.begin();
        int ans = 1e9;
        ans = min(ans,costs[0] + solve(indx0,days,costs,dp));
        ans = min(ans , costs[1] + solve(indx,days,costs,dp));
        ans = min(ans , costs[2] + solve(indx1 ,days,costs,dp));
        return dp[i] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //vector<vector<int>>dp(days.size()+1,vecctor<int>(,))
        vector<int>dp(367,-1);
        return solve(0,days,costs,dp);
    }
};