class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res;
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
            nums[i] %= 2;
        }
        for(int i = 1;i<n;i++){
            if(nums[i-1] == nums[i])res.push_back(i);
        }
      
        vector<bool>ans;
        for(auto u:queries){
            int lowIndex = u[0];
            int highIndex = u[1];
            if(lowIndex == highIndex){
                ans.push_back(true);
                continue;
            }
            if(res.size() >= 1){
                 auto it = upper_bound(res.begin(),res.end(),lowIndex);
                 
                 if(it!=res.end()){
                  
                    if(res[it-res.begin()]<=highIndex){
                        ans.push_back(false);
                    }else{
                        ans.push_back(true);
                    }
                 }else{
                    ans.push_back(true);

                 }
            }else{
                ans.push_back(true);
            }
               
            
            
            
        }
        return ans;
    }
};