public class Solution {
    public int MaxScoreSightseeingPair(int[] values) {
        int n = values.Length;
        List<int> maxSum = new List<int>();
        
        for(int i = 0 ; i < n - 1; i++){
            maxSum.Add(i + values[i]);
        }
        int ans = int.MinValue, mn = int.MaxValue;

        for(int i = n - 2; i >= 0 ;i--){
            mn = Math.Min(mn,(i+1) - values[i+1]);
            ans = Math.Max(ans,maxSum[i] - mn);
        }
        return ans;
    }
}