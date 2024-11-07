public class Solution {
    public int LargestCombination(int[] candidates) {
        int n = candidates.Length;
        //int mxLength = 0 ;
        int[] res = new int[25];
        for(int i = 24; i>= 0 ;i--){
            foreach(int u in candidates){
                if((u & ( 1 << i))!=0) res[i]++;
            }
            
        }
        return res.Max();
    }
}