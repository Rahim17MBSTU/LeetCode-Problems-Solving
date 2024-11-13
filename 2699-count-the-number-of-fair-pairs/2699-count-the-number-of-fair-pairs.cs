public class Solution {
    public int lower_bound(int [] nums,int i ,int value){
        int indx, low = i, high = nums.Length-1;
        indx = high + 1;
        while(low <= high){
            int mid = (low + high ) >> 1;
            if(nums[mid] >= value){
                high = mid - 1;
                indx = mid;
            }else{
                low = mid + 1;
            }
        }
        return indx;
    }
    public int upper_bound(int [] nums,int value){
        int indx, low = 0, high = nums.Length-1;
        indx = high + 1;
        while(low <= high){
            int mid = (low + high ) >> 1;
            if(nums[mid] <=  value){
                low = mid + 1;
            }else{
                indx = mid;
                high = mid - 1;
            }
        }
        return indx;
    }
    public long CountFairPairs(int[] nums, int lower, int upper) {
        Array.Sort(nums);
        long answer = 0;
        for(int i = 0 ; i < nums.Length; i++){
            int it1 = lower_bound(nums,i+1,lower - nums[i]);
            int it2 = upper_bound(nums, upper-nums[i]);
            if(it2>it1){
                answer += (it2-it1);
            }
        }
        return answer;
    }
}