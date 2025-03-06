public class Solution {
    public int[] FindMissingAndRepeatedValues(int[][] grid) {

        int n = grid.Length;
        int [] frequency = new int[n * n + 5];
        
        List<int> res = new List<int>();
        for(int i = 0;i < n;i++){
            for(int j = 0 ;j < n;j++){
                int x = grid[i][j];
               // Console.WriteLine(x);
                frequency[x]++;
                if(frequency[x] == 2){
                    res.Add(x);
                }
            }
        }
        for(int i = 1;i<=n*n;i++){
            if(frequency[i] == 0)res.Add(i);
        }
        return res.ToArray();
        
    }
}