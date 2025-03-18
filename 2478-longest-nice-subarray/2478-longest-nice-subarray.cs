public class Solution {
    public int LongestNiceSubarray(int[] nums) {
        int low = 1 , high = nums.Length;
        Func<int[],bool> check = (fre) => {
            for(int i = 0 ; i <=30;i++){
                if(fre[i] >= 2)return false;
            }
            return true;
        };
        Func<int,bool> f= (mid)=>{
            int[] fre = new int[31]; 
            for (int i = 0; i < mid; i++)
            {
                int temp = nums[i];
                int j = 0;

                while (temp > 0)
                {
                    if ((temp & 1) == 1)
                    {
                        fre[j]++;
                    }
                    temp >>= 1; 
                    j++;
                }
            }
           
            if(check(fre)){
                return true;
            }
            for(int i = 0 , j = mid ; j < nums.Length;i++,j++){
                int temp = nums[i];
                
                int k = 0;
                while (temp > 0)
                {
                    if ((temp & 1) == 1)
                    {
                        fre[k]--;
                    }
                    temp >>= 1; 
                    k++;
                }
                
                temp = nums[j];
                k = 0;
                while (temp > 0)
                {
                    if ((temp & 1) == 1)
                    {
                        fre[k]++;
                    }
                    temp >>= 1; 
                    k++;
                }
                if(check(fre)){
                    return true;
                }
            }
            return false;
        };
        int ans = 1;
        while(low <= high){
            int mid = (low + high)>>1; 
        
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