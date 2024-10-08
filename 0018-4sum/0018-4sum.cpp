class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        //map<pair<int,pair<int,pair<int,int>>>,int>mp;
        
        vector<vector<int>>vp;

        int n = nums.size();
        
        for(int i = 0 ;i <n-1;i++){
                if(i>0 && nums[i] == nums[i-1])continue;
            for(int j = i+1;j<n;j++){
                if(j != i+1 && nums[j] == nums[j-1])continue;
                int k = j+1, l = n-1;
                while(k<l){
                    long long int sum = 0;
                    sum = 0LL +nums[i] + nums[j] + nums[k] + nums[l] ;
                    if(target == sum ){
                       
                            vector<int>v{nums[i],nums[j],nums[k],nums[l]};
                          
                            vp.push_back(v);  
                        
                        k++;
                        l--;
                        while( k < l && nums[k] == nums[k-1])k++;
                        while(k < l && nums[l] == nums[l+1])l--;

                    }else if(sum > target ){
                        l--;
                    }else{
                        k++;
                    }
                }
            }
        }
        return vp;
    }
};