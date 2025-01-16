public class Solution {
    public int XorAllNums(int[] nums1, int[] nums2) {
        if(nums1.Length % 2== 0 && nums2.Length % 2 == 0) return 0;
        int xorValue = 0;
        int ans = 0;
        for(int i = 0 ; i < nums2.Length; i++) xorValue ^= nums2[i];
        Console.WriteLine(xorValue);
        int n = nums1.Length;
        if(nums1.Length % 2 == 1 && nums2.Length % 2==0){
            return xorValue;
        }
        for(int i = 0 ;i < nums1.Length;i++){
            int x = xorValue ^ nums1[i];
            ans ^= x;
        }
        return ans;
    }
}