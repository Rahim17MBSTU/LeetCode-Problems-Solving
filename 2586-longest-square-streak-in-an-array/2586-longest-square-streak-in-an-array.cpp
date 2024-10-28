class Solution {
public:
    
    int longestSquareStreak(vector<int>& v) {
        int n = v.size();
        vector<int>mp(1e5+10,0);
        for(auto u:v)mp[u]++;
        // set<int>s;
        // for(int i = 0 ; i < n; i++){
        //     mp[v[i]]++;
        //     s.insert(v[i]);
        // }
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