public class Solution {
    public bool IsPowerOfFour(int n) {
        int low = 0, high = 15;
        while(low<=high){
            int mid =(int)(low + high) / 2;
            long value = (long) Math.Pow(4,mid);
            if(value == n){
                return true;
            }else if(value > n){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return false;
    }
}