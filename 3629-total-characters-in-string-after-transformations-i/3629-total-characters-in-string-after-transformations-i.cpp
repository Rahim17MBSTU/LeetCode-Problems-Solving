class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int>v(27,0);
        for(auto u:s)v[u-'a']++;
        int mod = 1e9+7;
        int sum = 0;
        while(t--){
           // sum = 0;
            int temp = v[0], previous = v[0] % mod;
            for(int i = 1;i<=25;i++){
                temp = v[i] % mod;
                v[i] = previous % mod;
                //sum = sum + v[i] % mod;
                previous = temp;
            }
            v[0] = ( previous ) % mod;
            v[1] = v[1] + previous % mod;
            //sum = (sum + v[0]) % mod;
        }
        for(int i = 0 ;i <= 25;i++){
            sum += v[i] % mod;
            sum = sum % mod;
        }
        return sum;
    }
};