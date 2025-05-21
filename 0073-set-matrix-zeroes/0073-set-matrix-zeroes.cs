public class Solution {
    public void SetZeroes(int[][] matrix) {
        Queue<(int,int)> queue = new Queue<(int,int)>();
        int n = matrix.Length;
        int m = matrix[0].Length;
        for(int i = 0 ; i < n;i++){
            for(int j = 0;j <m;j++){
                if(matrix[i][j] == 0)queue.Enqueue((i,j));
            }
        }
        while(queue.Count>0){
            int x = queue.Peek().Item1;
            int y = queue.Peek().Item2;
            queue.Dequeue();
            for(int i = 0 ; i < m;i++){
                matrix[x][i] = 0;
            }
            for(int j = 0 ;j < n ;j++){
                matrix[j][y] = 0;
            }
        }
    }
}