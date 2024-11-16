public class Solution {
    public int[] ResultsArray(int[] nums, int k) {
        int n = nums.Length;
        int []result = new int[n-k+1];
        int last = -1,cnt=0;
        for(int i = 1 ; i <k;i++){
            if(nums[i-1]+1 == nums[i]){
                cnt++;
            }else{
               cnt = 0;
            }
        }
        
        if(cnt == k-1){
            result[0] = nums[k-1];
        }else{
            result[0] = -1;
        }
        
        for(int j=k;j<n;j++){
            if(nums[j-1]+1 == nums[j]){
                cnt++;
            }else{
                cnt = 0;
            }
            if(cnt >= k-1){
                result[j-k+1] = nums[j];
            }else{
                result[j-k+1] = -1;
            }
        }
        return result;
    }
}