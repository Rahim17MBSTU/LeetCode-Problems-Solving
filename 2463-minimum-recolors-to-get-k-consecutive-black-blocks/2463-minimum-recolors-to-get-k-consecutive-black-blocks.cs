public class Solution {
    public int MinimumRecolors(string blocks, int k) {
        int n = blocks.Length;
        int MinimumOperation = n, cnt = 0;
        for(int i = 0 ; i < k;i++){
            if(blocks[i] =='W')cnt++;
        }
        MinimumOperation = cnt;
        for(int i = 0, j = k; j <n;j++,i++){
            if(blocks[i] == 'W')cnt--;
            if(blocks[j] == 'W')cnt++;
            MinimumOperation = Math.Min(MinimumOperation, cnt);
        }
        return MinimumOperation;
    }
}