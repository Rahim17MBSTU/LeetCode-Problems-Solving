class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int minimumAnswer  = target,minimum = INT_MAX;
        
        sort(nums.begin(),nums.end()); int n = nums.size();
       
        for(int i = 0 ; i < n - 2; i++){
            
            int j = i + 1, k = n - 1;

            while(j < k){

                int sum = nums[i] + nums[j] + nums[k];
                
                int closest   = abs(target-sum);
                
                if(closest < minimum){
                    minimum = closest ; 
                    minimumAnswer = sum;
                }
                
                if(sum <= target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return minimumAnswer;
    }
};