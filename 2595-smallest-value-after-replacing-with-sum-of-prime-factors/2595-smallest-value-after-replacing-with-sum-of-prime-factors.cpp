class Solution {
public:

    int smallestValue(int n) {
        while(1){
            int new_n = 0, temp = n;

            for(int i=2;i*i<=n;i++){
                if(n%i == 0){
                    while(n%i == 0){
                        n/=i;
                        new_n += i;
                    }
                }
            }
            if(n>1)new_n += n;
            
            if(new_n == temp){
                return temp;
            }
            n = new_n; 
        }
        
    }
};