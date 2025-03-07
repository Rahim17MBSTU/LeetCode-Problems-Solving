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
        // for(int i = 0;i<=15;i++){
        //     Console.WriteLine($"i= {i} , vis[{i}]= {vis[i]}");
        // }
        for(int i = 2;i<=right;i++){
            if(!vis[i] && i>=left) prime.Add(i);
        }
        if(prime.Count < 2)return res.ToArray();
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