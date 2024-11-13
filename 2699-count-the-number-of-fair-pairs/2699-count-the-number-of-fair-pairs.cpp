class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
     
        long long ans = 0 ;
         for(int i = 0 ; i < nums.size();i++){
            long long int value1 = lower - nums[i];
            auto it1 = lower_bound(nums.begin(),nums.end(),value1) - nums.begin();
            if(it1 > i){
                int value2 = upper - nums[i];
                auto it2 = upper_bound(nums.begin(),nums.end(),value2) - nums.begin();
                if(it2 >= it1)
                ans += (it2 - it1);
                //cout <<"i0 = "<<i<<" "<<it1 << " "<<it2<< " "<<it2 - it1<<endl;
            }else{
                long long int value2 = upper - nums[i];
                auto it2 = upper_bound(nums.begin(),nums.end(),value2) - nums.begin();
                if(it2 > i)
                ans += (it2 - (i+1));
                //cout <<"i1 = "<<i<<" "<<it1 << " "<<it2<< " "<<it2 - (it1+1)<<endl;
            }
           
         }
         return ans;
    }
};