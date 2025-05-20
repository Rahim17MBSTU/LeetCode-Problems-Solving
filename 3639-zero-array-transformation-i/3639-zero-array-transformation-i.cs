public class Solution {
    public bool IsZeroArray(int[] nums, int[][] queries) {
        int n = nums.Length;
        int[] fre = new int[n+5];
        foreach(var u in queries){
            int x = u[0];
            int y = u[1];
            fre[x] -= 1;
            fre[y+1] += 1;
        }
        bool result = true;
        for(int i = 0; i <n ; i++){
            //Console.WriteLine(nums[i]-fre[i]+" ");
            if(i != 0)
                fre[i] += fre[i-1];
            if(nums[i] + fre[i] > 0){
                result = false;break;
            }
        }
        return result;
    }
}