public class Solution {
    public int[] ClosestPrimes(int left, int right) {
        bool [] vis = new bool[right + 5];
        List<int> prime = new List<int>();
        List<int> res = new List<int>{-1,-1};
        vis[0] = vis[1] = true;
        for(int i = 2; 1L*i*i <= right; i++){
            if(!vis[i]){
                for(int j = i*i;j<=right;j+=i){
                    vis[j] = true;
                }
            }
        }
       
        for(int i = left;i<=right;i++){
            if(!vis[i]) prime.Add(i);
        }
       
        int mx = (int)1e9;
        for(int i = 0 ; i < prime.Count-1;i++){
            int x = prime[i];
            int y = prime[i+1];
            if(mx > y-x){
                mx = y-x;
                res[0] = x;
                res[1] = y;
            }
        }
        return res.ToArray();
    }
}