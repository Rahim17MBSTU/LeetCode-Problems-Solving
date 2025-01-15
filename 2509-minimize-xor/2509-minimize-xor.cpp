class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt1 = 0 , cnt2 = 0;
        bitset<31>b2 = num2;
        bitset<31>b1 = num1;
        for(int i = 0 ; i < 31;i++){
            if(b2[i] == 1)cnt2++;
            if(b1[i] == 1)cnt1++;
        }
        if(cnt2 >= cnt1){
            int rem = cnt2 - cnt1;
            int res = 0;
           
            for(int i = 0;i < 31;i++){
                if(b1[i] == 0 && rem >= 1){
                    res += (1 << i);
                    rem--;
                }
                if(b1[i] == 1) res += (1 << i);
            }
            return res;
        }else{
           
            int res = 0;
           
            for(int i = 30;i >=0;i--){
               
                if(b1[i] == 1 && cnt2 >= 1) res += (1 << i),cnt2--;
            }
            return res;
        }
        
        //return num1;
    }
};