class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
     
        long long ans = 0 ;
         for(int i = 0 ; i < nums.size();i++){
            long long int value1 = lower - nums[i];
            auto it1 = lower_bound(nums.begin()+i+1,nums.end(),value1) - nums.begin();
            int value2 = upper - nums[i];
            auto it2 = upper_bound(nums.begin(),nums.end(),value2) - nums.begin();
            if(it2 >= it1)
            ans += (it2 - it1);
                
            
           
         }
         return ans;
    }
};