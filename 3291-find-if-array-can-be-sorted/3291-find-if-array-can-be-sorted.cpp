class Solution {
public:
  
    bool canSortArray(vector<int>& nums) {
        vector<pair<int,int>>vp;
        if(is_sorted(nums.begin(),nums.end())){
            cout<<"aise"<<endl;
            return true;
        }
        for(int i = 0 ;i < nums.size();i++){
            int bit = __builtin_popcount(nums[i]);
            vp.push_back({bit,nums[i]});
        }
        // for(auto u:vp){
        //     cout<<u.first<< " "<<u.second<<endl;
        // }
        vector<int>res,res1;

        int cnt = vp[0].first;
        int mx  = vp[0].second;
        int mx1 = vp[0].second;


        for(int i = 0 ; i < vp.size();i++){
            if(cnt == vp[i].first){
                mx = min(mx,vp[i].second);
                mx1 =max(mx1,vp[i].second);
            }else{
                res.push_back(mx);
                res.push_back(mx1);
                mx = vp[i].second;
                mx1 = mx;
                cnt= vp[i].first;
            }
        }
        
            res.push_back(mx);
             for(auto u:res)cout<<u<<" ";
        cout<<endl;
        //}
       if(is_sorted(res.begin(),res.end()) == true && is_sorted(res1.begin(),res1.end())){
        // cout<<"aise1"<<endl;
            return true;
        }
        else 
        return false;
    }
};