class Solution {
public:
    
    int longestSquareStreak(vector<int>& v) {
        
        vector<int>mp(1e5+2,0);
        for(auto u:v)mp[u]++;
        
        int mx = 0,cnt = 0 ;
        for(auto u:v){
            long long  x = u;
            int cnt = 1;
            while(1LL*x*x <= 1e5){
                x*=x;
                if(mp[x]>=1)cnt++;
                else{
                    break;
                }
            }
            mx = max(mx,cnt);
        }
        return mx>=2 ? mx : -1;
    }
};