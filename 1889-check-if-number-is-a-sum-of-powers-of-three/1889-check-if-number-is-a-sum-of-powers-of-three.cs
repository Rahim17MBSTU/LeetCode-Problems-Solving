public class Solution {
    public bool CheckPowersOfThree(int n) {
        for(int i = 15; i >= 0;i--){
            int x = (int)Math.Pow(3,i);
            if(x == n){
                return true;
            }else if(x < n ){
                n -= x;
            }
        }
        if(n != 0)
        return false;
        else return true;
    }
}