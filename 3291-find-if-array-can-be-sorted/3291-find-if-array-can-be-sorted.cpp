class Solution {
public:
  
    bool canSortArray(vector<int>& nums) {
        vector<pair<int,int>>vp;
        if(is_sorted(nums.begin(),nums.end())){
            return true;
        }
        for(int i = 0 ;i < nums.size();i++){
            int bit = __builtin_popcount(nums[i]);
            vp.push_back({bit,nums[i]});
        }
        vector<int>res,res1;
        int cnt = vp[0].first;
        int mn  = vp[0].second;
        int mx = vp[0].second;

        for(int i = 0 ; i < vp.size();i++){
            if(cnt == vp[i].first){
                mn = min(mn,vp[i].second);
                mx =max(mx,vp[i].second);
            }else{
                res.push_back(mn);
                res.push_back(mx);
                mn = vp[i].second;
                mx = mn;
                cnt= vp[i].first;
            }
        }
        
        res.push_back(mn);
        res1.push_back(mx);
        if(is_sorted(res.begin(),res.end()) && is_sorted(res1.begin(),res1.end())){
            return true;
        }
        else 
        return false;
    }
};