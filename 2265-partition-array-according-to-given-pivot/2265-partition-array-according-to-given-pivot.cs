public class Solution {
    public int[] PivotArray(int[] nums, int pivot) {
        int n = nums.Length;
        int[] Result = new int[n];
        
        int left = 0 , right = n - 1;
        
        for(int i = 0 , j = n - 1; i < n ; i++,j--){
            if(nums[i] < pivot){
                Result[left++] = nums[i];
            }if(nums[j] > pivot) {
                Result[right--] = nums[j];
            }
        }
        while(left <= right){
            Result[left++] = pivot;
        }
        return Result;
    }
}