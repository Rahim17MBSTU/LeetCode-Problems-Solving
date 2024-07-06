class Solution {
public:

    int smallestValue(int n) {
        if(n == 4)return 4;
        vector<bool>b (1e5+10, 0 );
        vector<int>prime;
        for(int i = 2;i*i<=1e5;i++){
            if(b[i] == 0){
                for(int j = i * i ;j <= 1e5;j+=i){
                    b[j] = 1;
                }
            }
        }
        for(int i=2;i<=1e5;i++){
            if(b[i] == 0) prime.push_back(i);
        }
        if(b[n] == 0){
            return n;
        }
        while(1){
            int new_n = 0;
            for(int i = 0 ;i < prime.size(); i++){
                if(n % prime[i] == 0){
                    while(n%prime[i] == 0 && n>1){
                        new_n += prime[i];
                        n/=prime[i];
                    }
                }
                if(prime[i]>n)break;
                
            }
            n = new_n;
            if(b[n] == 0)return n;
        }
    }
};