public class Solution {
    public int MaximumCount(int[] nums) {
        int p = 0 , n = 0;
        for(int i = 0 ; i < nums.Length; i++){
            if(nums[i] < 0)n++;

            if(nums[i] >0){
                p = nums.Length - i;
                break;
            }
        }
        return Math.Max(p,n);
    }
}