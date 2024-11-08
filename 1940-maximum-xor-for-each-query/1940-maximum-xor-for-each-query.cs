public class Solution {
    public int[] GetMaximumXor(int[] nums, int maximumBit) {
        int n = nums.Length;
        int[] Xor = new int[n];
        List<int> res = new List<int>();
        Xor[0] = nums[0];
        int mxValue = (1 << maximumBit ) - 1;
        for(int i = 1; i < n; i++){
            Xor[i] = nums[i] ^ Xor[i-1];
        }
        
        for(int i= n -1 ; i >= 0;i--){
            res.Add( mxValue - Xor[i] );
        }
        
       
        return res.ToArray();
    }
}