class Solution {
public:
    int subarrayGCD(vector<int>& v, int k) {

        long long ans = 0,cnt=0;
        int n = v.size();

        for(int i=0;i<n;i++){

            int x = 0;cnt=0;
            for(int j = i;j<n;j++){

                x = __gcd(x,v[j]);
                if(x % k == 0){
                    if(x == k){
                        cnt++; 
                    }
                }else{
                    break;
                }
            }
            ans+=cnt;
        }
        return ans;
    }
};