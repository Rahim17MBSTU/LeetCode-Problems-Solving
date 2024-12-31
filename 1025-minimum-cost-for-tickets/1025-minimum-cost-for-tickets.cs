public class Solution {
    public int solve(int i,int[] days,int[] costs,int[] dp){
        if(i >= days.Length){
            return 0;
        }
        if(dp[i] != -1)return dp[i];
        int value = days[i];
        int indxForOneDay = Array.BinarySearch(days,value+1);
        int indxForSevenDay = Array.BinarySearch(days,value+7);
        int indxForThirtyDay = Array.BinarySearch(days,value+30);

        if(indxForOneDay<0) indxForOneDay = ~indxForOneDay;
        if(indxForSevenDay<0) indxForSevenDay = ~ indxForSevenDay;
        if(indxForThirtyDay<0) indxForThirtyDay = ~ indxForThirtyDay;

        int ans = 1000000000 + 7;
        ans = Math.Min(ans,costs[0] + solve(indxForOneDay,days,costs,dp));
        ans = Math.Min(ans,costs[1] + solve(indxForSevenDay,days,costs,dp));
        ans = Math.Min(ans,costs[2] + solve(indxForThirtyDay,days,costs,dp));
        return dp[i] = ans;
    }
    public int MincostTickets(int[] days, int[] costs) {
        int []dp = new int[370];
        Array.Fill(dp,-1);
        return solve(0,days,costs,dp);
    }
}