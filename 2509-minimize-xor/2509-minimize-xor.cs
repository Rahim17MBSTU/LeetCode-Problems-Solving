public class Solution {
    public int MinimizeXor(int num1, int num2) {
        int cnt1 = 0 , cnt2 = 0 ;
        int p1 = 1 , p2 = 1;
        for(int i = 0 ; i < 31; i++){
            if((p1&num1) != 0)cnt1++;
            if((p2&num2) != 0)cnt2++;
            p1*=2;
            p2*=2;
        }
        if(cnt2 >= cnt1){
            int rem = cnt2 - cnt1;
            int result = 0;
            for(int i = 0; i <=30; i++){
                if((num1&(1<<i)) == 0 && rem >= 1 ){
                    result += (1 << i);
                    rem--;
                }
                else if((num1&(1<<i)) >= 1){
                    result += (1 << i);
                }
            }
            return result;
        }else{
            //Console.WriteLine(cnt1+" "+cnt2);
            int result = 0;
            for(int i = 30; i >= 0; i--){
                if(((num1&(1<<i)) != 0) && cnt2 >= 1 ){
                    result += (1 << i);
                    cnt2--;//Console.WriteLine("Hooo");
            
                }
                
            }
            return result;
        }
    }
}