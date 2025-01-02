public class Solution {
    public int[] VowelStrings(string[] words, int[][] queries) {
        int n = words.Length, m = queries.Length;
        int[] pre = new int[n+1], ans = new int[m];
        int indx = 0;
        
        foreach(string u in words){
            pre[indx] = 0;
            int sz = u.Length;
            if((u[0] == 'a' || u[0] =='e' || u[0] =='i' || u[0] =='o' || u[0] =='u') && 
            (u[sz-1] == 'a' || u[sz-1] =='e' || u[sz-1] =='i' || u[sz-1] =='o' || u[sz-1] =='u') )
            {
                pre[indx] = 1;
             
            }
            if(indx > 0){
                pre[indx] += pre[indx-1];
               
            }
            indx++;
        }
        
        for(int i = 0 ; i < m ;i++){
            int x = queries[i][0];
            int y = queries[i][1];
            int res = pre[y];
            if(x > 0){
                res -= pre[x-1];
            }
            ans[i] = res;
        }
        return ans;
        
    }
}