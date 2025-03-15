public class Solution {
    public int MinCapability(int[] nums, int k) {
        int low = nums.Min();
        int high = nums.Max();
        int ans = high;
        Func<int,bool> f = (mid) => {
            int cnt = 0;
            for(int i = 0; i < nums.Length; i++){
                if(nums[i] <= mid){
                    i++;
                    cnt++;
                }
            }
            return cnt >= k;
        };
        while(low <= high){
            int mid = (low + high) >> 1;
            if(f(mid)){
                ans = mid;
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
}