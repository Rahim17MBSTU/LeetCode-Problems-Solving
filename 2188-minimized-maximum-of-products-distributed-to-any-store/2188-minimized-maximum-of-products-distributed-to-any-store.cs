public class Solution {
    static bool f(int mid, int[] quantities,int n){
        
        int cnt = 0;
        foreach(var u in quantities){
                int x = u / mid;
                cnt += (u % mid == 0 ? x : x + 1);
        }
        //Console.Write(mid +" " + cnt);
        //Console.WriteLine();
        if(cnt <= n) return true;
        return false;
        
    }
    public int MinimizedMaximum(int n, int[] quantities) {
        int answer = 0;
        
        int low = 1,high = quantities.Max();
        
        while(low <= high){
            int mid = low + high >> 1;
            if(f(mid,quantities,n)){
                answer = mid ;
                high = mid - 1;
            }else{
                low = mid + 1;
                
            }
        }
        return answer ;
    }
}