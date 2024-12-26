class Solution {
public:
  
    int calculation(int i , int sum , vector<int>&v,int target){
        int n = v.size();
        
        if(i >= n){
            if(sum == target)return 1;
            else return 0;
        }

        int take = 0;
        
        take += calculation(i+1,sum+v[i],v,target) + calculation(i+1,sum-v[i],v,target); 
        
       return take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return  calculation(0,0,nums,target);
        
    }
};