public class Solution {
    public int WaysToSplitArray(int[] nums) {
        int n = nums.Length, ValidSplits = 0;
        long [] prefixSum = new long [n];
        
        for(int i = 0 ; i < n; i++){
            prefixSum[i] = nums[i];
            if(i > 0) prefixSum[i] += prefixSum[i-1];
        }
        for(int i = 0 ; i< n-1;i++){
            if(prefixSum[i] >= prefixSum[n-1] - prefixSum[i]) ValidSplits++;
        }
        return ValidSplits;
    }
}