public class Solution {
    public long RepairCars(int[] ranks, int cars) {
        long low = 1, high = 1000000000000000000;
        long ans = 0;
        Func<long,bool> f = (mid) =>{
            long cnt = 0;
            for(int i = 0 ; i < ranks.Length; i++){
               long l = 0, h = (long)Math.Sqrt(mid / ranks[i]);;
               // Console.Write("value  = ",ranks[i]);
                long temp = 0;
                while(l <= h){
                    long mid1 = (l + h) >> 1;
                    if(1L * ranks[i] * mid1 * mid1 <= mid){
                        l = mid1 + 1;
                        temp = mid1;
                    }else{
                        h = mid1 - 1;
                    }
                }
                //Console.WriteLine("temp = ",temp);
                cnt += temp;
            }
            return cnt >= cars;
        };
        while(low <= high){
            long mid = (low + high) >> 1;
            //Console.WriteLine("mid = ",mid);
            if(f(mid)){
                ans = mid ;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
}