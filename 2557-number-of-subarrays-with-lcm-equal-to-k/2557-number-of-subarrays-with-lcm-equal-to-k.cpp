class Solution {
public:
    int subarrayLCM(vector<int>& v, int k) {
        long long answer = 0 , count = 0;
        int n = v.size();
        for(int i = 0 ; i < n ; i++){
            int GCD = v[i],mul = 1, LCM = v[i];
            //count = 0;
            if(v[i] == k)count++;
            for(int j = i+1 ;j < n ;j++){
               
                GCD = __gcd(v[j],LCM);
                LCM = (LCM * v[j])/GCD;
                //cout << GCD << " " << LCM <<endl;
                //if(LCM % k == 0){
                    if(LCM == k)count++;
                //}
                if(LCM > k)break;
                
            }
            //cout<<"cnt= "<<count<<endl;
            
        }answer+=count;
        return answer ;
    }
};