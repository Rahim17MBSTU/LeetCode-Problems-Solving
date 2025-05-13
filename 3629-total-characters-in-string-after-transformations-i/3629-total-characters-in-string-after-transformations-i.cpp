class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int>v(27,0);
        for(auto u:s)v[u-'a']++;
        int mod = 1e9+7;
        int sum = s.size();
        while(t--){
       
            int temp = v[0], previous = v[0] % mod;
            for(int i = 1;i<=25;i++){
                temp = v[i] % mod;
                v[i] = previous % mod;
              
                previous = temp;
            }
            v[0] = ( previous ) % mod;
            v[1] = v[1] + previous % mod;
            sum = (sum + (previous == 0 ? 0 : previous)) % mod;
        }
        
        return sum;
    }
};