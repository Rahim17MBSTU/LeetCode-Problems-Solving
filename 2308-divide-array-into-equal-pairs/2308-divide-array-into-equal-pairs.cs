public class Solution {
    public bool DivideArray(int[] nums) {
        int [] Frequency = new int[505];
        foreach(var u in nums) Frequency[u]++;
        foreach(var u in Frequency) {
            if(u % 2 == 1) return false;
        }
        return true;
    }
}