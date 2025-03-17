class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int>mp;
        for(auto u:nums){
            mp[u]++;
        }
        int x = nums.size()/2;
        int ans = 0;
        for(auto u:mp){
            if(u.second % 2 == 1)ans++;
        }
        //cout << ans<<endl;
        return ans <= 0 ;
    }
};