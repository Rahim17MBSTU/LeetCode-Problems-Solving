class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int minimumAnswer  = target,minimum = INT_MAX;
        
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size() - 1;i++){

            if(i>0 && nums[i] == nums[i-1])continue;

            int j = i+1;

            int k = nums.size() - 1;

            while(j<k){

                int sum = nums[i] + nums[j] + nums[k];
                int closest   = abs(target-sum);
                
                if(closest < minimum){
                    minimum = closest ; 
                    minimumAnswer = sum;
                }
                if(sum < target){
                    j++;
                }else if(sum > target){
                    k--;
                }else{
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1])j++;
                    while(j<k && nums[k] == nums[k+1]) k--;

                }
            }
        }   
       
        return minimumAnswer;
    }
};