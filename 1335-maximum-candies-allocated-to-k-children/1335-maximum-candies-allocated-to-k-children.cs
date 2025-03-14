public class Solution {
    public int MaximumCandies(int[] candies, long k) {
        int low = 1 , high = (int) 1e7;
        int ans = 0;
        Func<int,bool> f = (mid) => {
            long  cnt = 0;
            for(int i = 0 ; i < candies.Length; i++){
                cnt +=  candies[i]/mid;
                
            }if(cnt >= k)return true;
            return false;
        };
        while(low <= high){
            int mid = low + high >> 1;
            if(f(mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
}