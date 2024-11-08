public class Solution {
    public int[] GetMaximumXor(int[] nums, int maximumBit) {
        int n = nums.Length;
        int[] Xor = new int[n];
        int[] res = new int[n];
        Xor[0] = nums[0];
        for(int i = 1; i < n; i++){
            Xor[i] = nums[i] ^ Xor[i-1];
        }
        // for(int i =0 ;i<n;i++){
        //     Console.Write(" "+Xor[i]);
        // }

        int mxValue = (1 << maximumBit ) - 1;
        
        for(int i= n -1 ; i >= 0;i--){
            res[i] =  mxValue - Xor[i] ;
        }
        Array.Reverse(res);
        return res;
    }
}